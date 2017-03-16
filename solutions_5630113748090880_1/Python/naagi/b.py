import sys

tests = input ()
for test in range (tests):
  n = input()
  cnt = [0] * 5000
  for i in range (2 * n - 1):
    a = map (int, sys.stdin.readline().split())
    for c in a:
      cnt[c] += 1
  ans = [str(i) for i in range (len(cnt)) if cnt[i] % 2 != 0]
  if len(ans) != n:
    print ("OUCH!!!")
    break    
  print ("Case #" + str(test + 1) + ": " + " ".join(ans))
