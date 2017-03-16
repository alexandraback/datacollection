import sys
sys.setrecursionlimit(10000)
f = open('garbled_email_dictionary.txt', 'r')
lines = f.readlines()
f.close()
lines = map(lambda x: x.rstrip(), lines)
mydict = {}
def add_rec(word, d):
  if len(word) == 0:
    d["ok"] = True
    return
  w = word[0]
  if w not in d: d[w] = {}
  add_rec(word[1:], d[w])

for word in lines:
  add_rec(word, mydict)

max_int = 10**9

cache = {}
def f(word, i, d, last_space, letter, last_change, v, max_v):
  if len(word) == i:
    if 'ok' in d:
      return v
    return max_int
  key = i, last_change, last_space, letter
  if key in cache: return cache[key] + v
  res = max_v

  if 'ok' in d: 
    res = min(res, f(word, i, mydict, 0, letter, last_change, v, res))

  w = word[i]
  if w in d:
    res = min(res, f(word, i+1, d[w], last_space+1, letter, last_change+1, v, res))

  if last_change >= 5:
    for k, dd in d.iteritems():
      if k == 'ok' or k == w: continue
      res = min(res, f(word, i+1, dd, last_space+1, k, 1, v+1, res))
  cache[key] = res - v
  return res

samples = int(sys.stdin.readline().rstrip())
for i in range(samples):
  s = sys.stdin.readline().rstrip()
  cache.clear()
  print "Case #%d: %d" % (i+1, f(s, 0, mydict, 0, None, 10, 0, max_int))
