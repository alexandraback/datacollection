def cut(S):
  C = 1
  tmp = 0.5
  while True:
    if S - tmp >= 0:
      ans =str(int(C))
      break
    C += 1
    tmp /= 2
    if C >= 40:
      break

  return S - 0.5**C, C

T = raw_input()
for t in range(int(T)):
  p,q = map(float, (raw_input()).split('/'))
  S = p/q
  S2, ans = cut(S)
  while S2>0.0:
    S2, tmp = cut(S2)
  if S2 != 0.0:
    ans = 'impossible'
  ans = str(ans)
  
  print 'Case #%d: %s' % (t+1, ans)
  

  
  