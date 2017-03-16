import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  N = int(sys.stdin.readline())

  items = []
  for i in range(N):
    a, b = map(int, sys.stdin.readline().strip().split())
    items.append((a, b))

  stars = 0
  cuts = 0
  while True:
    found = True
    # szukaj calego 2
    for i in range(len(items)):
      a, b = items[i]
      if b <= stars:
        del items[i]
        cuts += 1
        stars += 1
        if a != -1:
          stars += 1
        break
    else:
      found = False

    if not found:
      maxB = -1
      for i in range(len(items)):
        a, b = items[i]
        if -1 < a and a <= stars and maxB < b:
          bestI = i
          maxB = b
      if maxB == -1:
        break # no sol

      cuts += 1
      items[bestI] = (-1, maxB)
      stars += 1

  if not items:
    print 'Case #%d: %d' % (t, cuts)
  else:
    print 'Case #%d: Too Bad' % t
