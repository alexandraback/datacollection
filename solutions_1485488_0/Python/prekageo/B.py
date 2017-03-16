#!/usr/bin/env python

import sys
from collections import deque

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  H,N,M=map(int,rl().split())
  C=[]
  visited=[]
  for i in xrange(N):
    C.append(map(int,rl().split()))
    visited.append([False for i in xrange(M)])
  F=[]
  for i in xrange(N):
    F.append(map(int,rl().split()))

  def water(t):
    return

  def move(t1,x,y,dx,dy):
    if x+dx < 0 or x+dx>=M:
      return
    if y+dy < 0 or y+dy>=N:
      return
    if F[y][x]>C[y+dy][x+dx]-50:
      return
    if F[y+dy][x+dx]>C[y+dy][x+dx]-50:
      return
    if F[y+dy][x+dx]>C[y][x]-50:
      return
    t = 1.0*(-C[y+dy][x+dx]+50+H)/10
    if t<0 and t1==0:
      t=0
    else:
      t=max(t,0)
      if H-(t+t1)*10>=F[y][x]+20:
        t+=1
      else:
        t+=10
    return (t+t1,x+dx,y+dy)

  #print H
  #print F
  #print C
  q = []
  q.append((0,0,0))
  while len(q) > 0:
    t,x,y = q[0]
    q=q[1:]
    if visited[y][x]:
      continue
    visited[y][x]=True
    #print t,x,y
    if x==M-1 and y==N-1:
      return '%f' % t
    next=[]
    ret = move(t,x,y,-1,0)
    if ret is not None:
      #print t,x,y,'=>',ret
      next.append(ret)
    ret = move(t,x,y,0,-1)
    if ret is not None:
      #print t,x,y,'=>',ret
      next.append(ret)
    ret = move(t,x,y,1,0)
    if ret is not None:
      #print t,x,y,'=>',ret
      next.append(ret)
    ret = move(t,x,y,0,1)
    if ret is not None:
      #print t,x,y,'=>',ret
      next.append(ret)
    next.sort()
    q.extend(next)
    #q.sort()

def main():
  T = int(rl())
  for i in xrange(T):
    sys.stderr.write('%d\n'%i)
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
