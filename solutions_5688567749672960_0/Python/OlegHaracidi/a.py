queue = [0] * 10000000
queue[0] = 1
l = 0
r = 0
k = [1000000000] * 10000000
k[1] = 1
while l <= r:
  x = queue[l]
  l = l + 1
  if x + 1 < len(k) and k[x + 1] > k[x] + 1:
    k[x + 1] = k[x] + 1
    r = r + 1
    queue[r] = x + 1
  y = int(str(x)[::-1])
  if y < len(k) and k[y] > k[x] + 1:
    k[y] = k[x] + 1
    r = r + 1
    queue[r] = y
  
T = int(raw_input())
for i in xrange(T):
  N = int(raw_input())
  print "Case #{}: {}".format(i + 1, k[N])

