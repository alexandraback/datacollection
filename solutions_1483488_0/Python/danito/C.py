#!/usr/bin/python -tt


def main(line):
  lst = map(int, line.split(" "))
  A = lst.pop(0)
  B = lst.pop(0)
  l = len(str(A))

  count=0
  for n in range(A,B+1):
    istr = str(n)
    rep = []
    for j in range(l):
      m = int(istr[j:] + istr[:j])
      if m>n and m<=B and m not in rep:
        count += 1
        rep.append(m)
  return count


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    res = main(sys.stdin.readline().strip())
    print "Case #%d: %s" % (i + 1, res) 

