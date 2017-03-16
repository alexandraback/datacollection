import sys

small_cases = {
  1: '.',
  4: '.. ..',
  6: '... ...',
  8: '... ... ..',
  9: '... ... ...'
}

cases = int(sys.stdin.readline())
for case_no in range(1, cases+1):
  R, C, M = [int(val) for val in sys.stdin.readline().split()]
  grid = [['*' for j in range(C)] for i in range(R)]
  if R == 1 or C == 1:
    ans = 'c' + (R*C - M - 1)*'.' + M*'*'
    if C == 1:
      ans = '\n'.join(list(ans))
  elif R*C - M == 1:
    grid[0][0] = 'c'
    ans = ''
    for line in grid:
      for letter in line:
        ans += letter
      ans += '\n'
  elif R*C - M in [2, 3, 5, 7]:
    ans = 'Impossible'
  elif R == 2 or C == 2:
    if M % 2 != 0 or R*C - M == 2:
      ans = 'Impossible'
    else:
      ans = '*' * (M // 2) + '.' * (max(R, C) - (M // 2))
      if R == 2:
        ans = ans + '\n' + ans[:-1] + 'c'
      else:
        nans = ''
        for char in ans:
          nans += char + char + '\n'
        ans = nans[:-2] + 'c'
  elif R*C - M in [4, 6, 8, 9]:
    case = small_cases[R*C - M]
    pos = [0, 0]
    for char in case:
      if char == ' ':
        pos[0] += 1
        pos[1] = 0
      else:
        grid[pos[0]][pos[1]] = char
        pos[1] += 1
    grid[0][0] = 'c'
    ans = ''
    for line in grid:
      for letter in line:
        ans += letter
      ans += '\n'
  elif R*C - M < 3 * min(R, C):
    F = R*C - M
    cur = [0, 0]
    while F > 0:
      if R >= C:
        grid[cur[0]][cur[1]] = '.'
        F -= 1
        if F > 0:
          grid[cur[0] + 1][cur[1]] = '.'
          F -= 1
        else:
          grid[cur[0] + 1][cur[1]] = '.'
          grid[cur[0] + 2][cur[1] - 1] = '*'
        if F > 0:
          grid[cur[0] + 2][cur[1]] = '.'
          F -= 1
        cur[1] += 1
      else:
        grid[cur[0]][cur[1]] = '.'
        F -= 1
        if F > 0:
          grid[cur[0]][cur[1] + 1] = '.'
          F -= 1
        else:
          grid[cur[0]][cur[1] + 1] = '.'
          grid[cur[0] - 1][cur[1] + 2] = '*'
        if F > 0:
          grid[cur[0]][cur[1] + 2] = '.'
          F -= 1
        cur[0] += 1
    grid[0][0] = 'c'
    ans = ''
    for line in grid:
      for letter in line:
        ans += letter
      ans += '\n'
  else:
    F = R*C - M
    cur = [0, 0]
    while F > 0:
      grid[cur[0]][cur[1]] = '.'
      F -= 1
      if R >= C:
        cur[1] += 1
        if cur[1] == C:
          cur[0] += 1
          cur[1] = 0
      else:
        cur[0] += 1
        if cur[0] == R:
          cur[0] = 0
          cur[1] += 1
    if R >= C:
      if cur[1] == 1:
        grid[cur[0]][cur[1]] = '.'
        grid[cur[0] - 1][-1] = '*'
    else:
      if cur[0] == 1:
        grid[cur[0]][cur[1]] = '.'
        grid[-1][cur[1] - 1] = '*'
    grid[0][0] = 'c'
    ans = ''
    for line in grid:
      for letter in line:
        ans += letter
      ans += '\n'
  print("Case #{}:\n{}".format(case_no, ans.strip()))

