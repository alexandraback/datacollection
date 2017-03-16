def solve():
  D = input()
  ar = [int(_) for _ in raw_input().split()]

  def comp(thres):
    splits = sum((x - 1) / thres for x in ar)
    return splits + thres

  vals = [comp(x) for x in range(1, 1001)]
  return min(vals)


T = input()

for t in range(1, T + 1):
  print 'Case #%d: %d' % (t, solve())
