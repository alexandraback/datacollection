from sys import stdin
from math import sqrt, floor, ceil


def genpalin(root, odd=True):
  while True:
    yield int(str(root) + str(root)[::-1][odd:])
    if set(str(root)) == {'9'}:
      if odd:
        root = int('1'+'0'*(len(str(root))-1))
        odd = False
      else:
        odd = True
        root += 1
    else:
      root += 1


def ispalin(num):
  return str(num) == str(num)[::-1]


def palinsq(sqlow, squpp):
  low, upp = map(sqrt, [sqlow, squpp])
  low = ceil(low) if floor(low)**2 < sqlow else floor(low)
  upp = floor(upp) if ceil(upp)**2 > squpp else ceil(upp)
  gen = genpalin(int(str(low)[:(len(str(low))+1)//2]), len(str(low))%2 != 0)

  #print(low, upp)
  x = next(gen)
  while x < low:
    x = next(gen)

  count = 0
  while x <= upp:
    #print(x, end=', ')
    if ispalin(x**2):
      count += 1
    x = next(gen)
  #print()

  return count

T = int(stdin.readline().strip())
for i in range(T):
  x, y = map(int, stdin.readline().strip().split())
  print("Case #{}: {}".format(i+1, palinsq(x, y)))
