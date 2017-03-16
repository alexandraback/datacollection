import sys

T = int(raw_input())
for case in range(T):
  data = map(int, raw_input().split())
  N = data[0]
  S = data[1]
  p = data[2]
  scores = data[3:]
  scores.sort()
  scores.reverse()
  ans = 0
  for s in scores:
    best = s // 3
    if s % 3:
      best += 1
    if best >= p:
      ans += 1
    elif s >= 2 and s%3 != 1 and best+1 >= p and S > 0:
      ans += 1
      S -= 1
  print "Case #%d: %d" % (case+1, ans)
  