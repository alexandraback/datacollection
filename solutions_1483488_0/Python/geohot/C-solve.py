import sys

def rotateString(s, n):
  t = []
  for i in xrange(n, n+len(s)):
    t[len(t):] = s[i % len(s)]
  return ''.join(t)

def isRecycledPair(n, m):
  nstr = str(n)
  mstr = str(m)
  if len(nstr) == len(mstr):
    for n in xrange(1, len(nstr)):
      if rotateString(mstr, n) == nstr:
        return 1
  return 0

def recycledCount(n,A,B):
  nstr = str(n)
  ret = 0
  ls = set()
  for i in xrange(1, len(nstr)):
    rs = int(rotateString(nstr, i))
    if n < rs and rs <= B:
      ls.add(rs)
  return len(ls)

def calc(A, B):
  ret = 0
  for n in xrange(A, B+1):
    ret += recycledCount(n,A,B)
    #for m in xrange(n+1, B+1):
      #ret2 += isRecycledPair(n, m)
  return ret

def main():
  casecount = int(sys.stdin.readline())
  for i in range(1, casecount+1):
    a = map(int, sys.stdin.readline().strip().split(' '))
    out = calc(a[0], a[1])
    sys.stdout.write("Case #{0}: {1}\n".format(i,out))

if __name__ == "__main__":
  main()
