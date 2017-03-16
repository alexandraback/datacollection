
f = file('A-large.in')

n = int(f.readline())

mem = {}


def solve(A, motes, i=0):
  if A == 1: return len(motes)
  if A in mem and i in mem[A]:
    return mem[A][i]
  if A not in mem:
    mem[A] = {}

  if i == len(motes):
    return 0
  elif A > motes[i]:
    mem[A][i] = solve(A+motes[i], motes, i+1)
  elif motes[i] < A + A - 1:
    mem[A][i] = solve(A+A-1, motes, i) + 1
  else:
    s1 = solve(A+A-1, motes, i) + 1
    s2 = solve(A, motes, i+1) + 1
    mem[A][i] = min(s1, s2)
  return mem[A][i]


for i in range(1, n+1):
  A, N = map(int, f.readline().split())
  motes = map(int, f.readline().split())
  motes.sort()
  mem = {}
  print 'Case #%d: %d' % (i, solve(A, motes))
