"""Fractiles

Observation:
  * You can check whether a tile at complexity level X
    is 'G' by checking any of the K child tiles.
"""

try: input = raw_input
except NameError: pass

def solve(K, C, S):
  if C * S < K:
    return 'IMPOSSIBLE'

  tiles = set()
  for i in range(0, K, C):
    e = 1
    tile = 0
    for j in reversed(range(i, min(K, i+C))):
      tile += j * e
      e *= K
    tiles.add(tile + 1)

  return ' '.join(map(str, tiles))


T = int(input())
for t in range(1, T+1):
  K, C, S = map(int, input().split())
  print('Case #%d: %s' % (t, solve(K, C, S)))
