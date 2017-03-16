#!/usr/bin/env python3

from sys import stdin
from collections import deque

class Responder:
  def __init__(self):
    self.answer_no = 1
  def write(self, answer):
    print("Case #{}: {}".format(self.answer_no, answer))
    self.answer_no += 1

drs = [(0,1,'N'),(0,-1,'S'),(1,0,'E'),(-1,0,'W')]

def brute(X, Y):
  states = set()
  states.add((0,0,0,0))
  q = deque([(0,0,0,0)])
  while True:
    x,y,i,dr = q.popleft()
    ni = i+1

    for idx,(ix,iy,dr) in enumerate(drs):
      nx, ny = x+ni*ix, y+ni*iy
      if (nx,ny) == (X,Y):
        sol = []
        nidx,nix,niy,ndr = idx,ix,iy,dr
        while ni:
          sol.append(ndr)
          nx -= ni * nix
          ny -= ni * niy
          ni -= 1
          flag = False
          for i,d in enumerate(drs):
            if (nx, ny, ni, i) in states:
              nix,niy,ndr = d
              flag = True
              break
          assert flag

        return ''.join(d for d in sol[::-1])

      if not (nx,ny,ni,idx) in states:
        states.add((nx,ny,ni,idx))
        q.append((nx,ny,ni,idx))

if __name__ == "__main__":
  resp = Responder()
  for _ in range(int(stdin.readline())):
    X, Y = map(int, stdin.readline().split())
    solve = brute
    resp.write(solve(X,Y))
