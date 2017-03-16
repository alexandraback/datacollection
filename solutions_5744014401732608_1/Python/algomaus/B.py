#! /usr/bin/env python

def parse(lines):
  t = int(lines[0])
  act_line = 1
  cases = []
  for i in range(t):
    line = lines[act_line]
    act_line = act_line + 1
    cases.append(line.split(" "))
  return cases

def solve(case, i):
  B = int(case[0])
  M = int(case[1])
  
  if 2**(B-2) < M:
    print "Case #" + str(i+1) + ": " + "IMPOSSIBLE"
    return
  
  print "Case #" + str(i+1) + ": " + "POSSIBLE"
  
  removes = []
  solution = []
  for i in range(B):
    arr = []
    arr_remove = []
    for j in range(B):
      if j > i:
        arr.append('1')
        if j - i == B-1:
          arr_remove.append(1)
        else:
          arr_remove.append(2**(B-j+i-2))
      else:
        arr.append('0')
        arr_remove.append(0)
    solution.append(arr)
 
    removes.append(arr_remove)
    
  # here comes the work  
  act_num = 2**(B-2)
  
  
  while act_num > M:
    
    for k in range(B):
      diff = k+1
      for j in range(diff):
        i = diff-j-1
        if removes[i][j] > 0 and act_num - removes[i][j] >= M:
          act_num = act_num - removes[i][j]
          removes[i][j] = 0
          solution[i][j] = '0'
          
    # print solution
    #print act_num
    #for i in range(B):
     # print "".join(solution[i])
    
  # print solution
  for i in range(B):
    print "".join(solution[i])
    
with open('B-large.in', 'r') as f:
#with open('B-small-attempt1.in', 'r') as f:
#with open('input.txt', 'r') as f:
  cases = parse(f.read().splitlines())
for i in range(len(cases)):
  sol = solve(cases[i], i)
