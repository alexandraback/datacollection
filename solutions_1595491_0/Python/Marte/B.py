import sys
import string
inp = sys.stdin
T = int(inp.readline())

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  nums = map(int, inp.readline().strip().split(' '))
  n = nums.pop(0)
  s = nums.pop(0)
  p = nums.pop(0)
  assert n == len(nums)
  c = 0
  for num in nums:
    if min(num, (num+2)//3) >= p:
      c += 1
    elif s and min(num, (num+4)//3) >= p:
      c += 1
      s -= 1
  print c

