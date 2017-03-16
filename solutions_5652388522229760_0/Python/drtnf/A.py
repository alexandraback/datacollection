import sys

input = sys.stdin

def solve(N):
  if N == 0:
    return 'INSOMNIA'
  else:
    spare = {'0','1','2','3','4','5','6','7','8','9'}
    n = N
    for c in str(n):
      spare.discard(c)
    while len(spare)>0:
      n+=N
      for c in str(n):
        spare.discard(c)
    return str(n)
  

for case in range(int(input.readline())):
      values = input.readline().split()
      print("Case #"+ str(case+1) +":", solve(int(values[0])))
  
