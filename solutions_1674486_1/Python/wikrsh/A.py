# -*- coding: utf-8 -*-
# Google Code Jam 2012
# Round1C A

import sys

def ReadInts():
  line = sys.stdin.readline().rstrip().split()
  return map(int,line)

def mark(visits,children,i):
  if visits[i]:
    return True
  else:
    visits[i] = True
    queue = children[i]
    while queue:
      c = queue.pop(0)
      if visits[c]:
        return True
      else:
        visits[c] = True
        queue += children[c]
    
        
      
def solve(N,children,sclass):
  for c in sclass:
    visits = [False for _ in xrange(N)]
    if mark(visits,children,c):
      return True
  return False

def main():
  T = ReadInts()[0]
  for prob in xrange(1,T+1):
    N = ReadInts()[0]
    children = [[] for _ in xrange(N)]
    sclass = []
    for i in xrange(N):
      data = ReadInts()
      M = data[0]
      for c in data[1:]:
        children[c-1].append(i)
      if M == 0:
        sclass.append(i)
    if solve(N,children,sclass):
      ans = "Yes"
    else:
      ans = "No"
    print "Case #%d: %s"%(prob,ans)
    
if __name__ == '__main__':
  main()

