def gcd(pp, qq):
  while qq > 0:
    rr = pp % qq
    pp = qq
    qq = rr
  return pp

def solve(pp, qq):
  if (2**40)%qq != 0 or pp == 0:
    return False
  num = pp * ((2**40)/qq)
  for i in xrange(41):
    if num >= 2**(40-i):
      return i
  return False

tt = int(raw_input())
for t in xrange(1, tt+1):
  (p, q) = map(int,raw_input().split('/'))
  r = gcd(max([p, q]), min([p, q]))
  ans = solve(p/r, q/r)
  if ans == False:
    print 'Case #'+str(t)+': impossible'
  else:
    print 'Case #'+str(t)+': '+str(ans)

