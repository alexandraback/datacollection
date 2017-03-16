#Precomputation part
ind = 0
lim = 1000
store = []
while True:
  sq = ind**2
  if sq > lim:
    break;
  
  s = str(sq)
  t = str(ind)
  if s[-1] == '1' or s[-1] == '4' or s[-1] == '5' or s[-1] == '6' or s[-1] == '9':
    if s[::-1] == s and t[::-1] == t:
      store.append(sq)
  ind += 1

#Actual input intake and processing part
tc = int(input())
tco = tc
while tc:
  tc -= 1
  l,h = raw_input().split()
  l = int(l)
  h = int(h)
  print "Case #%s: %s" % (tco-tc, sum([1 for i in store if i>=l and i<=h]))
