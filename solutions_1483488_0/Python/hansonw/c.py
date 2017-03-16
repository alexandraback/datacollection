import sys

T = int(raw_input())
for case in range(T):
  A, B = map(int, raw_input().split())
  ans = 0
  for i in range(A, B):
    s = str(i)
    ms = {}
    for j in range(1, len(s)):
      if s[j] != '0':
        ni = int(s[j:] + s[:j])
        if ni > i and ni <= B:
          ms[ni] = 1
    ans += len(ms)
  print "Case #%d: %d" % (case+1, ans)