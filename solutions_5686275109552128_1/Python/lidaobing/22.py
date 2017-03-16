import sys



c = [[10000] * 1200 for i in range(1200)]

def init():
  c[0][0] = 0
  c[0][1] = 1
  for i in range(1, 1001): # time
    #print i
    for j in range(1, 1001): # n
      c[i][j] = min(c[i-1][j], c[i-1][j-1])
      #print i, j, '_', c[i][j]
      for k in range(1, j//2+1):
        t = c[i][k]+c[i][j-k]+1
        if t < c[i][j]:
          c[i][j] = t

def calc3(x, i):
  if i == 1:
    if x == 1:
      return 0
    else:
      return 10000

  if x == 1:
    return 0

  res = calc2(x-1, i-1)
  for x1 in range(1, x//2+1):
    res = min(calc2(x1, i)+calc2(x-x1, i)+1, res)
  return res

def calc2(x, i):
  return c[i][x]



def calc(a, i):
  return i + sum([calc2(x, i) for x in a])

def foo(ifile):
  ifile.readline()
  a = [int(x) for x in ifile.readline().split()]
  am = max(a)
  res = 100000
  for i in range(1, am+1):
    res = min(res, calc(a, i))
  return res

def main():
  init()
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
