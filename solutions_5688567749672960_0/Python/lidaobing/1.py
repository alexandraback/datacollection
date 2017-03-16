import sys

def reverse(i):
  res = 0
  while i > 0:
    res = res * 10 + (i % 10)
    i = i // 10
  return res

def fill():
  res = [-1] * (10**6+5)
  res[1] = 1
  count = {}
  count[1] = [1]
  for i in range(1, 10**6):
    t = count[i]
    count[i+1] = []
    for x in t:
      if x+1 > 10**6:
        continue
      if res[x+1] == -1:
        #print x+1, res[x+1]
        res[x+1] = i+1
        count[i+1].append(x+1)
        #print x+1, res[x+1], count[2]
      x2 = reverse(x)
      if x2 < 1 or x2 > 1000000:
        continue
      if res[x2] == -1:
        res[x2] = i+1
        count[i+1].append(x2)
    #print count[i+1]
  return res


AA = fill()


def foo(ifile):
  a = int(ifile.readline().strip())
  return AA[a]




def main():
  n = int(sys.stdin.readline().strip())
  for i in range(n):
    print 'Case #%d: %s' % (i+1, foo(sys.stdin))

main()
