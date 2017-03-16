import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  S = map(int, sys.stdin.readline().strip().split())
  del S[0]

  L = [None] * (20 * 100000 + 10)
  for mask in range(1 << 20):
    subSum = 0
    for i in range(20):
      if ((1 << i) & mask) != 0:
        subSum += S[i]
    if not L[subSum]:
      L[subSum] = [mask]
    else:
      L[subSum].append(mask)

  def checkMasks(masks):
    if masks and len(masks) > 1:
      n = len(masks)
      for i in range(n):
        for j in range(i + 1, n):
          if (masks[i] & masks[j]) == 0:
            return masks[i], masks[j]
    return None, None

  for masks in L:
    m1, m2 = checkMasks(masks)
    if m1:
      print 'Case #%d:' % t
      for i in range(20):
        if ((1 << i) & m1) != 0:
          print S[i],
      print ''
      for i in range(20):
        if ((1 << i) & m2) != 0:
          print S[i],
      print ''
      break
  else:
    print 'Case #%d: Impossible' % t
