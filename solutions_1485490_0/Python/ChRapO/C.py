import sys

T = sys.stdin.readline()

N = 0
M = 0
A = []
B = []

def solve(Ai, Bi, sum):
  if Ai == N or Bi == M:
    return sum

  s = 0
  s1 = 0
  s2 = 0
  if A[Ai*2+1] == B[Bi*2+1]: #same type
    s = min(A[Ai*2], B[Bi*2])

    AAi_prev = A[Ai*2]
    BBi_prev = B[Bi*2]        
    if AAi_prev - s == 0:
      B[Bi*2] = BBi_prev - s
      s1 = solve(Ai + 1, Bi, sum + s)
      B[Bi*2] = BBi_prev      
    else:
      A[Ai*2] = AAi_prev - s
      s2 = solve(Ai, Bi + 1, sum + s)
      A[Ai*2] = AAi_prev
  
  else:
    s1 = solve(Ai + 1, Bi, sum)
    s2 = solve(Ai, Bi + 1, sum)

  return max(s1, s2)

for case in range(0,int(T)):
  NM = [int(x) for x in sys.stdin.readline().split()]
  N = NM[0]
  M = NM[1]
  A = [int(x) for x in sys.stdin.readline().split()]
  B = [int(x) for x in sys.stdin.readline().split()]

  ret = solve(0,0,0)

  print "Case #%d: %d" % (case+1, ret) 
