import sys


def expand(a):
  for x in a:
    for i in range(x[1]):
      yield x[0], x[2]+i

def resolve(a):
  t1 = (360-a[0][0])*a[0][1]
  t2 = (360-a[1][0])*a[1][1]
  if t1 == t2:
    return 0
  if t1 > t2:
    if (t1-t2) >= 360 * a[1][1]:
      return 1
  if t2 > t1:
    if t2-t1 >= 360 * a[0][1]:
      return 1
  return 0

def foo(ifile):
  n = int(ifile.readline().strip())
  a = [None] * n
  for i in range(n):
    a[i] = [int(x) for x in ifile.readline().split()]
  b = list(expand(a))
  if len(b) > 2:
    return 0
  return resolve(b)




def main():
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
