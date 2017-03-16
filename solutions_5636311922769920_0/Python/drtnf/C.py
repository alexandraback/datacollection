import sys

input = sys.stdin

def solve(K, C, S):
  if S*C<K:
    return 'IMPOSSIBLE'
  else:
    s, i = '', 0
    while i < K:
      lev, acc = 0, 1
      while lev < C:
        acc += (i)*K**lev
        i+=1
        lev += 1
        if i==K:
          break
      s = s+' '+str(acc)    
    return s
  

for case in range(int(input.readline())):
      values = input.readline().split()
      print("Case #"+ str(case+1) +": "+ solve(int(values[0]), int(values[1]), int(values[2])))
  
