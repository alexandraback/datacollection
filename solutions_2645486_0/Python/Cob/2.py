T = int(raw_input())
for t in range(1, T + 1):
  (E, R, N) = map(int, raw_input().split())
  V = list(map(int, raw_input().split()))
  
  arr = dict()
  def max_gain(idx, j):
    if idx == N: return 0
    if (idx, j) in arr: return arr[(idx, j)]

    mx = -1
    for c in range(0, j + 1):
      gain = c * V[idx] + max_gain(idx + 1, min(j - c + R, E))
      if gain > mx:
        mx = gain

    arr[(idx, j)] = mx
    return mx

  print "Case #%d: %d" % (t, max_gain(0, E))
