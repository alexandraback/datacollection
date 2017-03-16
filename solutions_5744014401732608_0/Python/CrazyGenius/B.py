def possible(N,M):
  return (2**(N-2) >= M)

def solve(N,M):
  if(M == 1):
    tmp = ''
    for i in range(N-1):
      tmp += '0'
    tmp += '1'
    print tmp
    for i in range(N-1):
      tmp = ''
      for j in range(N):
        tmp += '0'
      print tmp
    return []

  full = 0
  while(2**full <= M):
    full += 1
  remain = int(M-(2**(full-1)))
  if(remain != 0):
    full += 1

  ans = []
  for i in range(N-1):
    tmp = ''
    for j in range(N):
      if(i < full):
        if(j < i):
          tmp = '1' + tmp
        else:
          tmp = '0' + tmp
      else:
        tmp = '0' + tmp
    ans.append(tmp)
  #print N,M
  #print 'remain:',remain,
  first = bin(M-1)[2::] + '1' 
  #print 'first:',first,'full:',full
  while(len(first) < N):
    if(len(first) == full-1):
      first = '1' + first
    else:
      first = '0' + first
  ans.append(first)
  return ans[::-1]

T = int(raw_input().strip())

for cas in range(1,T+1):
  print "Case #" + str(cas) + ":",
  N,M = raw_input().strip().split()
  N = int(N)
  M = int(M)
  if(not possible(N,M)):
    print 'IMPOSSIBLE'
  else:
    print 'POSSIBLE'
    ans = solve(N,M)
    for s in ans:
      print s
