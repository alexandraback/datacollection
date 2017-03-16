def pal(n):
  s = str(n)
  return s == s[::-1]

def sq(n):
  return int(n ** 0.5) ** 2 == n

t = int(raw_input())
for i in xrange(t):
  a, b = map(int, raw_input().split())
  cnt = 0
  for j in xrange(a, b + 1):
    if sq(j) and pal(j) and pal(int(j ** 0.5)):
      cnt += 1
  print "Case #%d: %d" % (i + 1, cnt)    
