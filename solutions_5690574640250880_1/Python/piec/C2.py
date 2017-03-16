import sys
import string

def parttt(N, R, C, multi = 2):
  cand = reversed(range(2, min(C,N)+1))

  for c in cand:
    if N%c == 0 and N/c >= multi and N/c <= R:
      return [c]*(N/c)

  for c in cand:
    newN = N - multi*c
    if newN > 0:
      try:
        return [c]*multi + parttt(newN, R-multi, C, 1)
      except:
        pass 
  raise Exception('notFound', '')


def solution(R, C, M):
  if R == 1:
    return "c" + "."*(C-M-1) + "*"*M
  if M == R*C - 1:
    return "\n".join(["c" + "*"*(C-1)] + ["*"*C]*(R-1))
  if M == 0:
    return "\n".join(["c" + "."*(C-1)] + ["."*C]*(R-1))


  #a1,a2 ... aR: a1==a2, ai!=1, 0<=ai <=C ai>=ai+1, sum_i ai =M
  try:
    parted = sorted(parttt(R*C -M, R, C))
  
    if len(parted) < 2:
      raise Exception('')
    if len(parted) > R:
      raise Exception('')
    if parted[0] == 1:
      raise Exception('')
    ordered = parted[::-1]
    if ordered[0] != ordered[1]:
      raise Exception('')
    if ordered[0] > C:
      raise Exception('')
    
    result = ["c" + "."*(ordered[0]-1) + "*"*(C-ordered[0])]
    for part in ordered[1:]:
      result.append("."*part + "*"*(C-part))
    result.extend(["*"*C]*(R-len(ordered)))

    return "\n".join(result)
  except:
    return "Impossible"



def rotate(solution):
  rows = solution.split()
  res=[]
  for x in zip(*rows):
    res.append(''.join(x))
  return '\n'.join(res)

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):

  params = string.split(sys.stdin.readline().strip())

  R = int(params[0])
  C = int(params[1])
  M = int(params[2])


  print 'Case #' + repr(casenum) + ':'

  if R > C:
    R,C = C,R
    sol = solution(R, C, M)
    if sol != 'Impossible':
      print rotate(sol)
    else:
      print sol
  else:
    print solution(R, C, M)

