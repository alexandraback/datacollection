import sys

def solve(p, q):
  if p * 2 ** 40 % q != 0:
    return "impossible"

  x = float(p) / float(q)
  k = 1
  while True:
    if 1.0 / 2 ** k <= x:
      return k
    else:
      k += 1

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

total_cases = int(raw_input())
for case_number in range(1, total_cases + 1):
  p, q = raw_input().split('/')
  result = solve(int(p), int(q))
  print "Case #{}: {}".format(case_number, result)
