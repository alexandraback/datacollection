#! /usr/bin/env python

import random

def parse(lines):
  t = int(lines[0])
  act_line = 1
  cases = []
  for i in range(t):
    line = lines[act_line]
    act_line = act_line + 1
    cases.append(line.split(" "))
  return cases

def solve(case, num):
  J = int(case[0])
  P = int(case[1])
  S = int(case[2])
  K = int(case[3])
  
  # keep in mind that counting starts from 1 in the output!
  
  combo_jp = []
  for i in range(J):
    arr = []
    for j in range(P):
      arr.append(0)
    combo_jp.append(arr)
  
  combo_js = []
  for i in range(J):
    arr = []
    for j in range(S):
      arr.append(0)
    combo_js.append(arr)
    
  combo_ps = []
  for i in range(P):
    arr = []
    for j in range(S):
      arr.append(0)
    combo_ps.append(arr)
    
  sol = []
  
  outfits = []
  
  for s in range(S):
    for p in range(P):
      for j in range(J):
        if combo_jp[j][p] < K and combo_js[j][s] < K and combo_ps[p][s] < K and (j,p,s) not in outfits:
          combo_jp[j][p] = combo_jp[j][p] + 1
          combo_js[j][s] = combo_js[j][s] + 1
          combo_ps[p][s] = combo_ps[p][s] + 1
          outfits.append((j,p,s))
          sol.append(str(j+1) + " " + str(p+1) + " " + str(s+1))
  
  print "Case #" + str(num+1) + ": " + str(len(sol))
  for line in sol:
    print line
    
#with open('C-large.in', 'r') as f:
with open('C-small-attempt4.in', 'r') as f:
#with open('input.txt', 'r') as f:
  cases = parse(f.read().splitlines())
for i in range(len(cases)):
  sol = solve(cases[i],i)
