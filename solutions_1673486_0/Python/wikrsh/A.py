# -*- coding: utf-8 -*-
# Google Code Jam 2012
# Round1A A

import sys

def ReadInts():
  line = sys.stdin.readline().rstrip().split()
  return map(int,line)

def ReadFloats():
  line = sys.stdin.readline().rstrip().split()
  return map(float,line)

def solve(A,B,probs):
  expected = []
  # keep typing
  cstroke_keep = B - A + 1
  istroke_keep = cstroke_keep + B + 1
  cprob = 1.0
  for p in probs:
    cprob *= p
  iprob = 1-cprob
  expected.append(cstroke_keep*cprob + istroke_keep*iprob)

  # backspace
  for nb in xrange(1,A+1):
    cstroke = cstroke_keep + 2*nb
    istroke = cstroke + B + 1
    cprob = 1.0
    for n in xrange(A-nb):
      cprob *= probs[n]
    iprob = 1-cprob
    expected.append(cstroke*cprob + istroke*iprob)

  # enter right away
  expected.append(1+B+1)

  return min(expected)

def main():
  T = ReadInts()[0]
  for t in xrange(1,T+1):
    A,B = ReadInts()
    probs = ReadFloats()
    print "Case #%d: %.6f"%(t,solve(A,B,probs))
    
if __name__=="__main__":
  main()
  
