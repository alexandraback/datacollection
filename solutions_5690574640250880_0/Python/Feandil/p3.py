#!/usr/env/python

from sys import stdin

def solve(R,C,M):
  if C == 1:
    if M < R:
      for i in range(0, M):
        print('*')
      for i in range(M, R - 1):
        print('.')
      print('c')
    else:
      print('Impossible')
  elif R == 1:
    if M < C:
      print('{}{}c'.format('*' * M, '.' * (C - 1 - M)))
    else:
      print('Impossible')
  elif M == (R * C) - 1:
    for i in range(0, R - 1):
      print('*' * C)
    print('{}c'.format('*' * (C - 1)))
  elif C == 2:
    if M + 4 <= 2 * R and M % 2 == 0:
      for i in range(0, M // 2):
        print('**')
      for i in range(M // 2, R - 1):
        print('..')
      print('.c')
    else:
      print('Impossible')
  elif R == 2:
    if (M + 4 <= 2 * C) and M % 2 == 0:
      print('{}{}.'.format('*' * (M // 2), '.' * (C - 1 - (M // 2))))
      print('{}{}c'.format('*' * (M // 2), '.' * (C - 1 - (M // 2))))
    else:
      print('Impossible')
  elif M <= (R - 2) * (C - 2):
    for i in range(0, M // (C - 2)):
      print('{}..'.format('*' * (C - 2)))
    leftover = M % (C - 2)
    if leftover != 0:
      print('{}{}'.format('*' * leftover, '.' * (C - leftover)))
      for i in range(M // (C - 2) + 1, R - 1):
        print('.' * C)
    else:    
      for i in range(M // (C - 2), R - 1):
        print('.' * C)
    print('{}c'.format('.' * (C - 1)))
  elif M <= (R * C) - 4:
    leftover = M - ((R - 2) * (C - 2))
    if leftover % 2 == 0:
      if (leftover // 2) < R - 2:
        for i in range(0, leftover // 2):
          print('*' * C)
        for i in range(leftover // 2, R - 2):
          print('{}..'.format('*' * (C - 2)))
        print('.' * C)
        print('{}c'.format('.' * (C - 1)))
      else:
        for i in range(0, R - 2):
          print('*' * C)
        left = (leftover // 2) - (R - 2)
        print('{}{}.'.format('*' * left, '.' * (C - 1 - left)))
        print('{}{}c'.format('*' * left, '.' * (C - 1 - left)))
    elif C == 3:
      if (M // 3 <= R - 2 and M % 3 == 0) or (M // 3 <= R - 3 and M % 3 == 1):
        for i in range(0, M // 3):
          print('*' * C)
        if (M % 3) != 0:
          print('{}{}'.format('*' * (M % 3), '.' * (3 - (M % 3))))
          for i in range((M // 3) + 1, R - 1):
            print('.' * C)
        else:
          for i in range(M // 3, R - 1):
            print('.' * C)
        print('{}c'.format('.' * (C - 1)))
      else:
        print('Impossible')
    elif R == 3:
      if (M // 3 <= C - 2 and M % 3 == 0) or (M // 3 <= C - 3 and M % 3 == 1):
        print('{}{}{}.'.format('*' * (M // 3), '*' if (M % 3 >= 1) else '', '.' * (C - 1 - (M // 3) - (1 if (M % 3 >= 1) else 0))))
        print('{}{}.'.format('*' * (M // 3), '.' * (C - 1 - (M // 3))))
        print('{}{}c'.format('*' * (M // 3), '.' * (C - 1 - (M // 3))))
      else:
        print('Impossible')
    else:
      leftover += 1
      if (leftover // 2) < R - 3:
        for i in range(0, leftover // 2):
          print('*' * C)
        for i in range(leftover // 2, R - 3):
          print('{}..'.format('*' * (C - 2)))
        print('{}...'.format('*' * (C - 3)))
        print('.' * C)
        print('{}c'.format('.' * (C - 1)))
      elif (leftover // 2) <= R - 3 + C - 3:
        for i in range(0, R - 3):
          print('*' * C)
        print('{}...'.format('*' * (C - 3)))
        left = (leftover // 2) - (R - 3)
        print('{}{}.'.format('*' * left, '.' * (C - 1 - left)))
        print('{}{}c'.format('*' * left, '.' * (C - 1 - left)))
      else:
        print('Impossible')
  else:
    print('Impossible')

def solve_prob():
    data = [int(i) for i in stdin.readline().strip().split()]
    solve(*data)

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}:'.format(i))
    solve_prob()
