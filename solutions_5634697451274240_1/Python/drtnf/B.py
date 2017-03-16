import sys

input = sys.stdin

def solve(stk):
  e = '+'
  n = 0
  for c in stk[::-1]:
    if c!= e:
      n+=1
    e = c    
  return str(n)
  

for case in range(int(input.readline())):
      values = input.readline().split()
      print("Case #"+ str(case+1) +": "+ solve(values[0]))
  
