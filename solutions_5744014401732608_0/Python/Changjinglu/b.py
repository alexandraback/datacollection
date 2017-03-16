
def print_result(case_index, feasible, g):
  if not feasible:
    print('Case #%d: IMPOSSIBLE' % case_index)
    return
  print('Case #%d: POSSIBLE' % case_index)
  print('\n'.join(''.join(map(str, row)) for row in g))

num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
  b, m = map(int, raw_input().split())
  g = [ [ 0 for c in range(b) ] for r in range(b) ]
  if m == 1:
    g[0][b - 1] = 1
    print_result(case_index, True, g)
    continue
  sinks = [ b - 1 ]
  tail = b - 1
  x = m
  feasible = True
  while x > 1:
    if x % 3 == 0:
      if tail - 3 < 0:
        feasible = False
        break
      for a in range(tail - 3, tail):
        for b in sinks:
          g[a][b] = 1
      sinks = list(range(tail - 3, tail))
      tail -= 3
      x //= 3
      continue
    if x % 2 == 1:
      if tail - 1 < 0:
        feasible = False
        break
      a = tail - 1
      for b in sinks:
        g[a][b] = 1
      tail -= 1
    if tail - 2 < 0:
      feasible = False
      break
    for a in range(tail - 2, tail):
      for b in sinks:
        g[a][b] = 1
    sinks = list(range(tail - 2, tail))
    tail -= 2
    x //= 2
  print_result(case_index, feasible, g)
