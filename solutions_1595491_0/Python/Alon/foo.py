#!/usr/bin/python
import sys

def calc(N, S, p, totals):
  normal_cand = 0
  sup_cand = 0
  for total in totals:
     if total >= p + max(p-1,0)*2:
       normal_cand +=1
     elif total >= p + max(p-2,0)*2:
       sup_cand += 1 
    
  return normal_cand + min(sup_cand, S)

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1, n+1):
    line = d[j].split(' ')
    N = int(line[0])
    if N == 0:
      print "Case #%d: 0" % j
      continue
    S = int(line[1])
    p = int(line[2])
    totals = [int(t) for t in line[3:]]
    
    print "Case #%d: %d" % (j, calc(N, S, p, totals))

main()
