from math import sqrt, ceil

br = open('c.in')
br = open('C-small-attempt0.in')
pw = open('c-small.out', 'w')

t = int(br.readline())

def ispal(n):
  return n == n[::-1]

def isps(n):
  s = int(ceil(sqrt(n)))
  return s * s == n

def naive(a, b):
  r = 0
  for i in range(a, b + 1):
    if isps(i):
      s = int(ceil(sqrt(i)))
      if ispal(str(i)) and ispal(str(s)):
        r += 1
  return r

for i in range(1, t + 1):
  a, b = map(int, br.readline().split())
  r = naive(a, b)
  print 'Case #%d: %d' % (i, r)
  pw.write('Case #%d: %d\n' % (i, r))
