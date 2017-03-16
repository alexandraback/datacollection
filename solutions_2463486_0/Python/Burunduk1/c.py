import sys
import bisect

b = set()

def pal(x):
  return x == x[::-1]

def add(x):
  x = int(x)
  if pal(str(x * x)):
    b.add(x * x)

def go(s, i):
  if i == 8:
    return
  if i > 0:
    add(s + s[::-1])
    add(s[:-1] + s[::-1])
  for t in {'0', '1', '2'}:
    go(s + t, i + 1)
  
def get(n):
  return bisect.bisect_right(a, n)

go('', 0)
add('3')
a = sorted(b)
tn = int(sys.stdin.readline())
for t in range(tn):
  l, r = list(map(int, sys.stdin.readline().strip().split(' ')))
  print('Case #%d: %d' % (t + 1, get(r) - get(l - 1)))
