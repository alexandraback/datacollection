#! /usr/bin/env python

def asList(line):
  lineSplitted = line.split(' ')
  a = []
  for i in lineSplitted:
    a.append(int(i))
  return a

def parse(lines):
  t = int(lines[0])
  cases = []
  actLine = 1
  for i in range(t):
    n = int(lines[actLine])
    actLine = actLine + 1
    lists = []
    for j in range(2*n-1):
      lists.append(asList(lines[actLine]))
      actLine = actLine + 1
    cases.append(lists)
  return cases
  
def solve(lists):
  listsSorted = sorted(lists)
  occurrences = {}
  
  n = len(listsSorted[0])
  cells = []
  for aList in listsSorted:
    for j in aList:
      if j in occurrences.keys():
        occurrences[j] = occurrences[j] + 1
      else:
        occurrences[j] = 1
        
  badguys = []
  for j in occurrences:
    if occurrences[j] % 2 != 0:
      badguys.append(j)
      
  badguys = sorted(badguys)
  stra = []
  for i in badguys:
    stra.append(str(i))
  
  return ' '.join(stra)
    
#with open('B-large.in', 'r') as f:
with open('B-small-attempt2.in', 'r') as f:
  cases = parse(f.read().splitlines())
for i in range(len(cases)):
  result = solve(cases[i])
  print "Case #" + str(i+1) + ": " + result
