INF = 10**19

def construct(a, b):
  return (abs(int("".join(a)) - int("".join(b))), "".join(a), "".join(b))


def solve2(a, b):
  ans = (INF, '', '')
  for i in range(len(a)):
    if (a[i] == '?'):
      for d in range(10):
        a[i] = str(d)
        ans = min(ans, solve2(a, b))
      a[i] = '?'

  if ans[0] == INF:
    for i in range(len(b)):
      if (b[i] == '?'):
        for d in range(10):
          b[i] = str(d)
          ans = min(ans, solve2(a, b))
        b[i] = '?'

  if ans[0] == INF:
    return construct(a, b)
  return ans


def fill_from_pos(a, b, pos):
  a = list(a)
  b = list(b)
  swp = (a[pos] < b[pos])
  for i in range(pos + 1, len(a)):
    if a[i] == '?':
      a[i] = '9' if swp else '0'
    if b[i] == '?':
      b[i] = '0' if swp else '9'
  return construct(a, b)


def solve():
  a, b = [list(x) for x in input().split()]
#  print("\n", "".join(a), "".join(b))
#  ans2 = solve2(a, b)

  n = len(a)
  assert(len(b) == n)

  ans = (INF, '', '')
  for i in range(n):
    if a[i] == b[i] == '?':
      a[i], b[i] = '0', '1'
      ans = min(ans, fill_from_pos(a, b, i))
      a[i], b[i] = '1', '0'
      ans = min(ans, fill_from_pos(a, b, i))
      a[i] = b[i] = '0'
    elif a[i] == '?':
      if b[i] != '0':
        a[i] = str(int(b[i]) - 1)
        ans = min(ans, fill_from_pos(a, b, i))
      if b[i] != '9':
        a[i] = str(int(b[i]) + 1)
        ans = min(ans, fill_from_pos(a, b, i))
      a[i] = b[i]
    elif b[i] == '?':
      if a[i] != '0':
        b[i] = str(int(a[i]) - 1)
        ans = min(ans, fill_from_pos(a, b, i))
      if a[i] != '9':
        b[i] = str(int(a[i]) + 1)
        ans = min(ans, fill_from_pos(a, b, i))
      b[i] = a[i]
    elif a[i] != b[i]:
      ans = min(ans, fill_from_pos(a, b, i))

  ans = min(ans, construct(a, b))
#  print(ans, construct(a, b), a, b)
#  if (ans != ans2):
#    print(ans, ans2)
#  assert(ans == ans2)
  print(ans[1], ans[2])


T = int(input())
for t in range(1, T + 1):
  print("Case #" + str(t) + ": ", end='')
  solve()

