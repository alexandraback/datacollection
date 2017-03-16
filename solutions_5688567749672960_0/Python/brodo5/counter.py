import math
import itertools

f = open("A-small-attempt1.in", "r")
tests = int(f.readline())
out = open("A-small.out", "w")
for i in range(tests):
  n = int(f.readline())
  a = 0
  current = 1
  while current != n:
    flipped = int(str(current)[::-1])
    next_flipped = int(str(current + 1)[::-1])
    if current + 1 == n:
      current += 1
    elif flipped == n:
      current = flipped
    elif flipped > current + 1 and flipped <= n:
      if next_flipped <= n and next_flipped > flipped + 1:
        current += 1
      else:
        current = flipped
    else:
      current += 1
    a += 1

  out.write("Case #{1}: {0}\n".format(a + 1, i + 1))
