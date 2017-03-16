#!/usr/bin/env python
import sys
import pdb

def calc(a, motes):
  op = 0
  ops = []
  motes.sort()
  if a == 1:
    return len(motes);
  for i, m in enumerate(motes):
    ops.append(op+(len(motes)-i))
    if a > m:
      a += m
      ops[-1] -= 1
    else:
      while a <= m:
        op += 1
        a += (a-1)
      a += m
  return min(ops)
    
    
if __name__ == "__main__":
  if len(sys.argv) > 1:
    ifile = open(sys.argv[1])
  else:
    ifile = sys.stdin
  if len(sys.argv) > 2:
    ofile = open(sys.argv[2])
  else:
    ofile = sys.stdout
  for i in range(int(ifile.readline())):
    a,n = map(int, ifile.readline().split())
    motes = map(int, ifile.readline().split())
    print "Case #%i: %s" % (i+1, calc(a, motes))
