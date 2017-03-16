import sys


c = [[10000] * 5 for i in range(5)]
c[1][1] = 1
c[1][2] = 2
c[1][3] = 3
c[1][4] = 4

c[2][1] = 2
c[2][2] = -1
c[2][3] = 4
c[2][4] = -3

c[3][1] = 3
c[3][2] = -4
c[3][3] = -1
c[3][4] = 2

c[4][1] = 4
c[4][2] = 3
c[4][3] = -2
c[4][4] = -1

m = {
  'i': 2,
  'j': 3,
  'k': 4,
}

def init():
  pass

def pow2(a, x):
  return mul([a] * (x % 4))


def total(a, x):
  return pow2(mul(a), x)

def mul(a):
  res = 1
  minus = 0
  for x in a:
    if x < 0:
      minus = 1 - minus
      x = -x
    res = c[res][x]
    if res < 0:
      minus = 1 - minus
      res = -res
  if minus == 0:
    return res
  return -res

def get(a, n1, n2):
  res = 1
  step = 0
  n = [n1, n2]
  for x in a:
    res = mul([res, x])
    if res == n[step]:
      step += 1
    if step == 2:
      return 'YES'
  return 'NO'


win = 'RICHARD'
lose = 'GABRIEL'
def foo(ifile):
  x, r, c = [int(x) for x in ifile.readline().split()]
  if x == 1:
    return lose

  if x == 2:
    if r*c%2 == 0:
      return lose
    else:
      return win

  if x == 3:
    if r*c%3 != 0:
      return win
    if r>=3 and c >= 2:
      return lose
    if r >= 2 and c >= 3:
      return lose
    return win

  if x == 4:
    if r*c%4 != 0:
      return win
    if r >= 4 and c >= 3:
      return lose
    if r >= 3 and c >= 4:
      return lose
    return win



def main():
  init()
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
