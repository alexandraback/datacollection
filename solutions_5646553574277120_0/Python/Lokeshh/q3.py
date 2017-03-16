def f(v, i, S, memo):
    if i >= len(v): return 1 if S == 0 else 0
    if (i, S) not in memo:  # <-- Check if value has not been calculated.
        count = f(v, i + 1, S, memo)
        count += f(v, i + 1, S - v[i], memo)
        memo[(i, S)] = count  # <-- Memoize calculated result.
    return memo[(i, S)]     # <-- Return memoized value.

def g(v, S, memo):
  subset = []
  for i, x in enumerate(v):
    # Check if there is still a solution if we include v[i]
    if f(v, i + 1, S - x, memo) > 0:
      subset.append(x)
      S -= x
  return subset

def find(v, S):
    memo = dict()
    return g(v, S, memo) != []

def haha(D, V):
    D.sort()
    res = 0
    for i in range(1, V+1):
        if not find(D, i):
            for p in range(1, V):
                if p not in D:
                    D.append(p)
                    break
            D.sort()
            res += 1
    return res

for i in range(input()):
    C, D, V = map(int, raw_input().split())
    D = map(int, raw_input().split())
    print 'Case #' + str(i+1) + ': ' + str(haha(D, V))
