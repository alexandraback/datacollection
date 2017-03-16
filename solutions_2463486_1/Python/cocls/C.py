from itertools import combinations

FILE_IN = "C-large-1.in"
FILE_OUT = "C-large-1.out"

def sqrt_int(n):
  if n == 0:
    return 0
  l = len(bin(n))-2
  x = 2**((l+1)/2)
  while True:
    y = (x + n/x)/2
    if y >= x:
      return x
    x = y

def len_num(i):
  ans = 0
  if i == 1:
    return 3
  if i%2 == 0:
    if i/2 >= 4:
      ans += (i/2-1)*(i/2-2)*(i/2-3)/6
    if i/2 >= 3:
      ans += (i/2-1)*(i/2-2)/2
    if i/2 >= 2:
      ans += i/2-1
    ans += 2
  elif i%2 == 1:
    if i/2 >= 4:
      ans += (i/2-1)*(i/2-2)*(i/2-3)/3
    if i/2 >= 3:
      ans += (i/2-1)*(i/2-2)
    if i/2 >= 2:
      ans += 3*(i/2-1)
    ans += 5
  return ans


def smaller(a, i):
  a_str = str(a);
  if i == 1:
    if a == 0:
      return 0
    if a == 1:
      return 1
    elif a == 2:
      return 2
    else:
      return 3
  if a_str[0] >= '3':
    return len_num(i)
  elif a_str[0] == '2':
    ans = 0
    if i%2 == 0:
      if i/2 >= 4:
        ans += (i/2-1)*(i/2-2)*(i/2-3)/6
      if i/2 >= 3:
        ans += (i/2-1)*(i/2-2)/2
      if i/2 >= 2:
        ans += i/2-1
      ans += 1
      if a >= int('2' + '0'*(i-2) + '2'):
        ans += 1
    elif i%2 == 1:
      if i/2 >= 4:
        ans += (i/2-1)*(i/2-2)*(i/2-3)/3
      if i/2 >= 3:
        ans += (i/2-1)*(i/2-2)
      if i/2 >= 2:
        ans += 3*(i/2-1)
      ans += 3
      if a >= int('2' + '0'*(i-2) + '2'):
        ans += 1
      if a >= int('2' + '0'*(i/2-1) + '2' + '0'*(i/2-1) + '2'):
        ans += 1
    return ans
  elif a_str[0] == '1':
    ans = 0
    if i%2 == 0:
      # case 1: 8 '1's
      if i/2 >= 4:
        for comb in combinations(range(i/2-1), 3):
          num_str = '1' + '0'*(i-2) + '1'
          for loc in comb:
            num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                       '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 2: 6 '1's
      if i/2 >= 3:
        for comb in combinations(range(i/2-1), 2):
          num_str = '1' + '0'*(i-2) + '1'
          for loc in comb:
            num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                       '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 3: 4 '1's
      if i/2 >= 2:
        for loc in xrange(i/2-1):
          num_str = '1' + '0'*(i-2) + '1'
          num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                     '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 4: 2 '1's
      if int('1' + '0'*(i-2) + '1') <= a:
        ans += 1
    elif i%2 == 1:
      # case 1: 9 '1's
      if i/2 >= 4:
        for comb in combinations(range(i/2-1), 3):
          num_str = '1' + '0'*(i/2-1) + '1' + '0'*(i/2-1) + '1'
          for loc in comb:
            num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                       '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 2: 8 '1's
      if i/2 >= 4:
        for comb in combinations(range(i/2-1), 3):
          num_str = '1' + '0'*(i-2) + '1'
          for loc in comb:
            num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                       '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 3: 7 '1's
      if i/2 >= 3:
        for comb in combinations(range(i/2-1), 2):
          num_str = '1' + '0'*(i/2-1) + '1' + '0'*(i/2-1) + '1'
          for loc in comb:
            num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                       '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 4: 6 '1's
      if i/2 >= 3:
        for comb in combinations(range(i/2-1), 2):
          num_str = '1' + '0'*(i-2) + '1'
          for loc in comb:
            num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                       '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 5: 5 '1's
      if i/2 >= 2:
        for loc in xrange(i/2-1):
          num_str = '1' + '0'*(i/2-1) + '1' + '0'*(i/2-1) + '1'
          num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                     '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 6: 4 '1's
      if i/2 >= 2:
        for loc in xrange(i/2-1):
          num_str = '1' + '0'*(i-2) + '1'
          num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                     '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 7: 4 '1's  and 1 '2'
      if i/2 >= 2:
        for loc in xrange(i/2-1):
          num_str = '1' + '0'*(i/2-1) + '2' + '0'*(i/2-1) + '1'
          num_str = (num_str[:(1+loc)] + '1' + num_str[(1+loc+1):(i-loc-2)] +
                     '1' + num_str[(i-loc-1):])
          if int(num_str) <= a:
            ans += 1
      # case 8: 3 '1's
      if int('1' + '0'*(i/2-1) + '1' + '0'*(i/2-1) + '1') <= a:
        ans += 1
      # case 9: 2 '1's
      if int('1' + '0'*(i-2) + '1') <= a:
        ans += 1
      # case 10: 2 '1's and 1 '2'
      if int('1' + '0'*(i/2-1) + '2' + '0'*(i/2-1) + '1') <= a:
        ans += 1
    return ans

with open(FILE_IN, "r") as file_in:
  with open(FILE_OUT, "w") as file_out:
    test_case = int(file_in.readline().strip())
    for t in xrange(test_case):
      (a, b) = map(int, file_in.readline().split())
      a = sqrt_int(a-1)
      b = sqrt_int(b)
      ans = 0
      a_len = len(str(a))
      b_len = len(str(b))
      # main_part
      for i in xrange(a_len, b_len):
        ans += len_num(i)
      ans -= smaller(a, a_len)
      ans += smaller(b, b_len)
      file_out.write("Case #%d: %d\n" % (t+1, ans))
