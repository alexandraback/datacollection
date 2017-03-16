import sys

def run(t):
  N = int(raw_input())
  bffs = [0] + map(int, raw_input().split())

  max_loop = 0
  for start in range(1, N + 1):
    visited = [False] * (N+1)
    k = start
    loop = 0
    while not visited[k]:
      visited[k] = True
      loop += 1
      k = bffs[k]
    if k == start:
      max_loop = max(max_loop, loop)

  paths = {}
  for start in range(1, N + 1):
    visited = [False] * (N+1)
    k = start
    path_len = 0
    prev = -1
    while not visited[k]:
      visited[k] = True
      path_len += 1
      if bffs[k] == prev:
        if not k in paths:
          paths[k] = {prev: path_len}
        elif not prev in paths[k]:
          paths[k][prev] = path_len
        else:
          paths[k][prev] = max(paths[k][prev], path_len)
        break
      prev = k
      k = bffs[k]

  max_paths = [0]
  visited = [False] * (N+1)
  for k, path in paths.iteritems():
    for prev, length in path.iteritems():
      if prev in paths and k in paths[prev]:
        if not visited[prev] and not visited[k]:
          max_paths.append(length + paths[prev][k] - 2)
          visited[k] = True
          visited[prev] = True


  print('Case #{}: {}'.format(t, max(sum(max_paths), max_loop)))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
