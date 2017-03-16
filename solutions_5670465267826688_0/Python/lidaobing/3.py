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

def foo(ifile):
  _, xx = [int(x) for x in ifile.readline().split()]
  a = [m[x] for x in ifile.readline().strip()]
  if total(a, xx) != -1:
    return 'NO'
  if xx > 10:
    a2 = a * 10
  else:
    a2 = a * xx
  return get(a2, 2, 4)


def main():
  init()
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
