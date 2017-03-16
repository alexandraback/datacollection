import copy

T = int(raw_input())
r, n, m, k = map(int, raw_input().split())
print "Case #1:"
for i in range(r):
  t = set(map(int, raw_input().split()))
  offers = []
  for k1 in range(2, 6):
    for k2 in range(2, 6):
      for k3 in range(2, 6):
        b = copy.deepcopy(t)
        b.discard(1)
        b.discard(k1)
        b.discard(k2)
        b.discard(k3)
        b.discard(k1 * k2)
        b.discard(k1 * k3)
        b.discard(k2 * k3)
        b.discard(k1 * k2 * k3)
        offers.append([len(b), [k1, k2, k3]])
  offers.sort()           
  print ''.join(map(str, offers[0][1]))



