T = input()
for i in range(1, T+1):
  r, t = [int(x) for x in raw_input().split(" ")]
  lo = 0
  hi = 10**9
  while lo < hi:
    mid = (lo + hi + 1) / 2
    fmid = mid * (2*mid + 2*r - 1)
    if fmid <= t:
      lo = mid
    else:
      hi = mid - 1
  print "Case #" + str(i) + ":", lo

