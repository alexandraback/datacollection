from collections import defaultdict

digits = [
  ("ZERO", "Z", 0),
  ("TWO", "W", 2),
  ("FOUR", "U", 4),
  ("EIGHT", "G", 8),
  ("SIX", "X", 6),
  ("FIVE", "F", 5),
  ("THREE", "T", 3),
  ("ONE", "O", 1),
  ("SEVEN", "S", 7),
  ("NINE", "I", 9),
]

def solve():
  s = input()
  cnt = defaultdict(int)
  for c in s:
    cnt[c] += 1
  ans = ''
  for d in digits:
    n = cnt[d[1]]
    for c in d[0]:
      cnt[c] -= n
    ans += str(d[2]) * n
  print("".join(sorted(ans)))


T = int(input())
for t in range(1, T + 1):
  print("Case #" + str(t) + ": ", end='')
  solve()

