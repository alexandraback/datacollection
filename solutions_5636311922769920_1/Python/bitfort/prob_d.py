'''
t = raw_input()

for n in xrange(int(t)):
  K, C, S = tuple(map(int, raw_input().split()))
  print 'Case #{}: {}'.format(n + 1, ' '.join(map(str, [i + 1 for i in xrange(K)])))
'''

t = raw_input()

def print_ans(n, ans):
  if ans is None:
    print 'Case #{}: IMPOSSIBLE'.format(n + 1)
  else:
    print 'Case #{}: {}'.format(n + 1, ' '.join(map(str, ans)))


def posn(K, C, path):
  assert len(path) <= C
  if len(path) == 1:
    return path[0]
  if C == 1:
    return path[0]

  # each tree below us is of height...
  h = K ** (C - 1)

  car = path[0]
  cdr = path[1:]
  return h * (car - 1) + posn(K, C - 1, cdr)
  

def solve(K, C, S):
  check = []
  up_to = 0
  for s in xrange(S):
    todo = []
    for c in xrange(C):
      if up_to == K:
        break
      up_to += 1
      todo.append(up_to)
    if len(todo) == 0:
      return check
    check.append(posn(K, C, todo))
  return check


for n in xrange(int(t)):
  K, C, S = tuple(map(int, raw_input().split()))

  if C * S < K:
    ans = None
  else:
    ans = solve(K, C, S)
  print_ans(n, ans)
    
