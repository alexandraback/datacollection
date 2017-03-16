#!/usr/bin/env python

import sys, bisect

def play_deceitful_war(Naomi, Ken, n):
  points = 0
  for i in xrange(n):
    if Naomi[-1] > Ken[-1]:
      del Naomi[-1]
      del Ken[-1]
      points+=1
    else:
      del Naomi[0]
      del Ken[-1]
  return points


def play_war(Naomi, Ken, n):
  points = 0
  for naomi in Naomi:
    ken = select_war(Ken, naomi)
    if naomi > Ken[ken]:
      points+=1
    del Ken[ken]
  return points
    
def select_war(Ken, naomi):
  i = bisect.bisect_right(Ken, naomi)
  if len(Ken) > i: return i
  else: return 0
  

def solve(N, K, n):
  return (play_deceitful_war(sorted(N),sorted(K),n), play_war(sorted(N),sorted(K),n))

def __main__():
  cases_no = int(sys.stdin.readline())
  for case_no in xrange(cases_no):
      n = int(sys.stdin.readline())
      N = map(float,sys.stdin.readline().split())
      K = map(float,sys.stdin.readline().split())
    
      res = solve(N, K, n)
      print "Case #%d: %d %d" % (case_no+1, res[0], res[1])

__main__()
