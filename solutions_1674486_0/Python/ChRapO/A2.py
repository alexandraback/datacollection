import sys

N = 0
E = []
was = []

def solve(i):
  if len(E[i]) == 0:
    return False
  for e in E[i]:
    if was[e] == 1:
      return True
    was[e] = 1
    if solve(e):
      return True
  return False

T = sys.stdin.readline()

for case in range(0,int(T)):
  N = int(sys.stdin.readline())
  E = []

  for i in range(0,N):
    VE = [int(x)-1 for x in sys.stdin.readline().split()][1:]
    E.append(VE)

  is_something = False
  for i in range(0,N):
    was = [0 for k in range(0,N)]
    ret = False
    if len(E[i])>1:
      ret = solve(i)
    if ret == True:
      is_something = True
      break
      
  if is_something:
    print "Case #%d: Yes" % (case+1)
  else:
    print "Case #%d: No" % (case+1) 
