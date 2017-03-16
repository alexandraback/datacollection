f = file('B-small-attempt1.in')

cases = int(f.readline())



memoizer = {}


def solve(MAX_E, E, R, acts, i = 0):
  if len(acts) == i:
    return 0
  if str(R) + '-' + str(i) in memoizer:
    return memoizer[str(E) + '-' + str(i)]
  sols = [0 for k in range(0, E+1)]
  #for j in range(max(0, E - MAX_E + R), E + 1):
  for j in range(0, E + 1):
    sols[j] = acts[i] * j + solve(MAX_E, min(E - j + R, MAX_E) , R, acts, i + 1)

  memoizer[str(E) + '-' + str(i)] = max(sols)
  return memoizer[str(E) + '-' + str(i)]
  return max(sols)



for i in range(1, cases + 1):
  E, R, N = map(int, list(f.readline().split()))
  memoizer = {}
  acts = map(int, list(f.readline().split()))
  sol = solve(E, E, R, acts)

  #sol = solve2(r, t)

  print 'Case #' + str(i) + ': ' + str(sol)