import math
def sq(t):
  x = math.sqrt(t)
  while ((x + 1) * (x + 1) <= t): x += 1
  while (x * x > t): x -= 1
  return x
FIN = open("A-large (2).in", "r")
#FOUT = open("output.txt", "w")

def solve():
  R, T = map(int, FIN.readline().split())
  l = 0
  r = 2000000000000000000 + 10
  while (l + 1 < r):
    mid = (l + r) // 2
    if ((2 * R + 1 + 2 * (mid - 1)) * mid <= T): l = mid
    else: r = mid
  return l
t = int(FIN.readline())
for i in range(1, t + 1):
  print(str("Case #" + str(i) + ": " + str(solve())))