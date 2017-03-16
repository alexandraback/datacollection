import sys
data = sys.stdin.readlines()
allpairs = {}

def pairs(l, i, minnum, maxnum):
  global allpairs
  s = str(i)
  r = 0
  for j in range(1, l+1):
    t = int(s[j:] + s[:j])
    if i > t and t >= minnum and t <= maxnum:
      u = str(i) + str(t)
      if u not in allpairs:
        allpairs[u] = 1
        r += 1
  return r

cases = int(data[0])
for i in range(cases):
  allpairs = {}
  d = data[i+1].split(' ')
  di = [int(j) for j in d]
  s, t = di[0], di[1]
  l = len(str(s))
  res = 0
  for j in range(s, t+1):
    res += pairs(l, j, s, t)
  print "Case #%d: %d" % (i+1, res)