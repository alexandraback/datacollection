import os
import math

def get_single_result(dp, cur, index, base, a_digit, b_digit):
  diff_digit = int(a_digit) - int(b_digit)
  value_of_a_minus_b = dp[(cur-1, index)][0]+diff_digit*base
  all_digits_a = str(a_digit)+dp[(cur-1, index)][1]
  all_digits_b = str(b_digit)+dp[(cur-1, index)][2]
  return (value_of_a_minus_b, all_digits_a, all_digits_b)

def solve(origin_a, origin_b):
  length = len(origin_a)
  # dp[(right_to_left, 0~3)] = (value_of_a-b, digit_a, digit_b)
  # 0: a>b max
  # 1: a>b min
  # 2: a<b min
  # 3: a<b max
  dp = {}
  for i in range(4):
    dp[(-1, i)] = (0, '', '')
  base = 1
  for i in range(length):
    cur = length - i - 1
    if origin_a[cur] != '?' and origin_b[cur] != '?':
      cur_digit_a = int(origin_a[cur])
      cur_digit_b = int(origin_b[cur])
      if origin_a[cur] < origin_b[cur]:
        # 4xx 6xx
        if (i - 1, 0) in dp:
          dp[(i, 2)] = get_single_result(dp, i, 0, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 2)] = get_single_result(dp, i, 2, base, cur_digit_a, cur_digit_b)

        if (i - 1, 3) in dp:
          dp[(i, 3)] = get_single_result(dp, i, 3, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 3)] = get_single_result(dp, i, 1, base, cur_digit_a, cur_digit_b)
      elif origin_a[cur] > origin_b[cur]:
        # 6xx 4xx
        if (i - 1, 0) in dp:
          dp[(i, 0)] = get_single_result(dp, i, 0, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 0)] = get_single_result(dp, i, 2, base, cur_digit_a, cur_digit_b)

        if (i - 1, 3) in dp:
          dp[(i, 1)] = get_single_result(dp, i, 3, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 1)] = get_single_result(dp, i, 1, base, cur_digit_a, cur_digit_b)
      else:
        # 4xx 4xx
        if (i - 1, 0) in dp:
          dp[(i, 2)] = get_single_result(dp, i, 0, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 2)] = get_single_result(dp, i, 2, base, cur_digit_a, cur_digit_b)

        if (i - 1, 3) in dp:
          dp[(i, 3)] = get_single_result(dp, i, 3, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 3)] = get_single_result(dp, i, 1, base, cur_digit_a, cur_digit_b)

        if (i - 1, 0) in dp:
          dp[(i, 0)] = get_single_result(dp, i, 0, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 0)] = get_single_result(dp, i, 2, base, cur_digit_a, cur_digit_b)

        if (i - 1, 3) in dp:
          dp[(i, 1)] = get_single_result(dp, i, 3, base, cur_digit_a, cur_digit_b)
        else:
          dp[(i, 1)] = get_single_result(dp, i, 1, base, cur_digit_a, cur_digit_b)

    base = base * 10
  if (length-1, 1) in dp and (length-1, 2) in dp:
    return dp[(length-1, 1)]
  elif (length-1, 2) in dp:
    return dp[(length-1, 2)]
  else:
    return (0, '', '')


global_min = None
global_min_a = None
global_min_b = None

def dfs(cur_a, cur_b, origin_a, origin_b, cur_index, is_a):
  global global_min, global_min_a, global_min_b

  if cur_index >= len(origin_a):
    if is_a:
      dfs(cur_a, cur_b, origin_a, origin_b, 0, is_a=False)
    else:
      cur_min = abs(int(cur_a) - int(cur_b))
      if global_min is None or cur_min < global_min:
        global_min = cur_min
        global_min_a = cur_a
        global_min_b = cur_b
      elif cur_min == global_min:
        if int(cur_a) < int(global_min_a) or (int(cur_a) == int(global_min_a) and int(cur_b) < int(global_min_b)):
          global_min_a = cur_a
          global_min_b = cur_b
    return

  if is_a:
    if origin_a[cur_index] == '?':
      for i in range(10):
        dfs(cur_a + str(i), cur_b, origin_a, origin_b, cur_index+1, is_a)
    else:
      dfs(cur_a + origin_a[cur_index], cur_b, origin_a, origin_b, cur_index+1, is_a)
  else:
    if origin_b[cur_index] == '?':
      for i in range(10):
        dfs(cur_a, cur_b + str(i), origin_a, origin_b, cur_index+1, is_a)
    else:
      dfs(cur_a, cur_b + origin_b[cur_index], origin_a, origin_b, cur_index+1, is_a)

def solve_easy(origin_a, origin_b):
  length = len(origin_a)
  global global_min, global_min_a, global_min_b
  global_min = None
  global_min_a = None
  global_min_b = None
  dfs('', '', origin_a, origin_b, 0, is_a=True)
  return global_min, global_min_a, global_min_b


fin = open('B-small-attempt0.in', 'r')
fout = open('B.out', 'w')
for i, line in enumerate(fin):
  if i == 0:
    t = int(line)
    continue
  parts = line.strip().split()

  res = solve_easy(parts[0], parts[1])

  out_str = 'Case #%d: %s %s\n' % (i, res[1], res[2])
  print out_str
  fout.write(out_str)
fin.close()
fout.close()
