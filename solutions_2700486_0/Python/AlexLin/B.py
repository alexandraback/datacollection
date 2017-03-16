import sys
import numpy as np

lines = [L.strip() for L in sys.stdin.read().splitlines()]
lines = iter(lines)
T = int(next(lines))

def getLevel(X, Y):
  return max(abs(X + Y), abs(X - Y)) // 2

def getTri(lv):
  return (lv) * (2 * lv - 1)

def cal(N, lv, X, Y):
  if X==0 and N<getTri(lv + 1):
    return 0.0
  side_length = 2 * lv
  remain = N - getTri(lv)
  # print("remain",remain)
  if (Y + 1 + side_length <= remain):
    return 1.0
  dp = np.zeros(shape=remain+1, dtype=np.float64)
  dp[0] = 1.0
  for i in range(1, remain + 1):
    for j in range(min(i, side_length), -1, -1):
      if (j < side_length):
        if (i - 1 - j >= side_length):
          dp[j] = 0.0
        else:
          dp[j] *= 0.5
      if (j == 0):
        continue
      if (i - 1 - j == side_length):
        dp[j] += dp[j - 1]
      else:
        dp[j] += dp[j - 1] * 0.5
    #print("Iter: ", i, dp)
  return np.sum(dp[Y + 1:min(remain, side_length)+1])





for i in range(T):
  N, X, Y = list(map(int, next(lines).split()))
  lv = getLevel(X, Y)
  ans = 0.0
  #print(lv)
  #print(getTri(lv + 1))
  if (N >= getTri(lv + 1)):
    ans = 1.0
  elif (N <= getTri(lv)):
    ans = 0.0
  else:
    ans = cal(N, lv, X, Y)
  print("Case #%d: %.8f" % (i + 1, ans))
