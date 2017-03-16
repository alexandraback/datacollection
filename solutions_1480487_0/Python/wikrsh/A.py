# -*- coding: utf-8 -*-
# Google Code Jam 2012
# Round1B A

import sys

def ReadInts():
  line = sys.stdin.readline().rstrip().split()
  return map(int,line)

def solve(N,s):
  X = sum(s)
  ans = []
  # if N == 2:
  #   for i in xrange(N):
  #     if s[i] == min(s):
  #       ans.append((float(max(s)-s[i])/(2*X) + 0.5)*100)
  #     else:
  #       ans.append((float(min(s)-s[i])/(2*X) + 0.5)*100)
  #   return ans
  notlose = []
  Z = X
  for i in xrange(N):
    if float(2*X-s[i])/(N-1) <= s[i]:
      notlose.append(i)
      Z -= s[i]
  for i in xrange(N):
    if i in notlose:
      ans.append(0.0)
    else:
      require_point = float(X+Z)/(N-len(notlose)) - s[i]
      ans.append(100.0*require_point/X)
  return ans

def main():
  T = ReadInts()[0]
  for prob in xrange(1,T+1):
    data = ReadInts()
    N = data[0]
    s = data[1:]
    ans = solve(N,s)
    print "Case #%d:"%(prob),
    for i in xrange(N):
      print "%.6f"%(ans[i]),
    print

if __name__ == "__main__":
  main()
  
