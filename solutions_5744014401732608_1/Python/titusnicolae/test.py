#!/usr/bin/python
from sys import stdout
def best(x):
  if x==0: return 0
  i=0
  x-=1
  while(x):
    x/=2
    i+=1
  return i


testcases = int(raw_input())
for testcase in range(testcases):
  b, m = map(int, raw_input().split())
  if m>2**(b-2):
    stdout.write("Case #"+str(testcase+1)+": IMPOSSIBLE\n")
  else:
    l = [0 for _ in range(b)]
    ret = [['0' for _ in range(b)] for _ in range(b)]   
    for i in range(best(m)+1):
      for j in range(i+1, best(m)+1):
        ret[i][j]='1'
    ret[0][b-1]='1'
    for i in range(0,best(m)+2): 
      if (1<<i) & (m-1):
        ret[i+1][b-1]='1'
      
    stdout.write("Case #"+str(testcase+1)+": POSSIBLE\n")
    stdout.write('\n'.join(map(lambda x:''.join(x), ret)))
    stdout.write('\n')
