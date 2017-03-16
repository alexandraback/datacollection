from sys import stdin

def solve(a, N, M):
  max_y = [0 for i in range(N)]
  max_x = [0 for i in range(M)]
  for y in range(N):
    for x in range(M):
      max_x[x] = max(max_x[x], a[y][x])
      max_y[y] = max(max_y[y], a[y][x])
  for y in range(N):
    for x in range(M):
      if a[y][x] != min(max_x[x], max_y[y]):
        return 'NO'
  return 'YES'

n = int(stdin.readline())

for i in range(n):
  line = stdin.readline().split()
  N = int(line[0])
  M = int(line[1])
  a = []
  for t in range(N):
    a.append(stdin.readline().split())
  print 'Case #' + str(i + 1) + ':', solve(a, N, M)
print

