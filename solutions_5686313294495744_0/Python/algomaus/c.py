#! /usr/bin/env python

import random

def parse(lines):
  t = int(lines[0])
  act_line = 1
  cases = []
  for i in range(t):
    n = int(lines[act_line])
    act_line = act_line + 1
    case = []
    for j in range(n):
      case.append(lines[act_line])
      act_line = act_line + 1
    cases.append(case)
  return cases

def find_num(case, occ_prefix, occ_suffix):
  case_shuffled = random.shuffle(case)
  num = 0
  
  occ_prefix_n = {}
  for k in occ_prefix:
    occ_prefix_n[k] = occ_prefix[k]
  occ_suffix_n = {}
  for k in occ_suffix:
    occ_suffix_n[k] = occ_suffix[k]
  
  for topic in case:
    splitted = topic.split(' ')
    if occ_prefix_n[splitted[0]] > 1 and occ_suffix_n[splitted[1]] > 1:
      num = num + 1
      occ_prefix_n[splitted[0]] = occ_prefix_n[splitted[0]] - 1
      occ_suffix_n[splitted[1]] = occ_suffix_n[splitted[1]] - 1
  return num

def solve(case):
  bestnum = 0
  n = len(case)
  occ_prefix = {}
  occ_suffix = {}
  
  used_prefix = {}
  used_suffix = {}
  
  for topic in case:
    splitted = topic.split(' ')
    if splitted[0] in occ_prefix.keys():
      occ_prefix[splitted[0]] = occ_prefix[splitted[0]] + 1
    else:
      occ_prefix[splitted[0]] = 1
      
    if splitted[1] in occ_suffix.keys():
      occ_suffix[splitted[1]] = occ_suffix[splitted[1]] + 1
    else:
      occ_suffix[splitted[1]] = 1
      
  for i in range(1000):
    n = find_num(case, occ_prefix, occ_suffix)
    if n > bestnum:
      bestnum = n
  

      
  return str(bestnum)
    
#with open('A-large.in', 'r') as f:
with open('C-small-attempt4.in', 'r') as f:
  words = parse(f.read().splitlines())
for i in range(len(words)):
  wordSorted = solve(words[i])
  print "Case #" + str(i+1) + ": " + wordSorted
