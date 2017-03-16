import sys

def foo(ifile):
  a = ifile.readline().split()[1]
  res = 0
  b = 0
  for i, x in enumerate(a):
    x = int(x)
    if x == 0:
      continue
    if b < i:
      res += (i-b)
      b = i
    b += x
  return res



def main():
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
