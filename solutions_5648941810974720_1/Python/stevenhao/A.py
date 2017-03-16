from collections import *

r = raw_input


names = 'ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE'.split()
order = [(0, 'Z'), (6, 'X'), ( 2, 'W'), (8, 'G'), (3, 'H'), (4, 'U'), (5, 'F'), (7, 'V'), (1, 'O'), (9, 'N')]

def solve(s):
  freqs = defaultdict(int)
  for i in s:
    freqs[i] += 1

  ans = []
  for i, ch in order:
    while freqs[ch] > 0:
      ans.append(str(i))
      for k in names[i]:
        freqs[k] -= 1
  for k in freqs:
    if freqs[k] > 0:
      print 'bad'
  ans.sort()
  return ''.join(map(str, ans))


T = int(r())
for t in range(1, T + 1):
  s = r()
  ans = solve(s)
  print 'Case #%d: %s' % (t, ans)

