def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1),

  N = readint()
  Naomi = readarray(float)
  Ken = readarray(float)

  Naomi.sort()
  Ken.sort()

  scoreDeceit = 0
  i = 0
  j = 0
  t = 0
  while t < N:
    if Naomi[i] > Ken[j]:
      j += 1
      scoreDeceit += 1
    i += 1
    t += 1
  
  scoreNormal = 0
  balance = 0
  i = N-1
  k = N-1
  t = 0
  while t < N:
    if Ken[k] > Naomi[i]:
      k -= 1
    else:
      scoreNormal += 1
    i -= 1
    t += 1

  print scoreDeceit, scoreNormal
