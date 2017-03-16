f = open('B-small-attempt0.in')
o = open('output.txt', 'w')
n = int(f.readline())

for i in range(n):
  row = [int(x) for x in f.readline().split(' ')]
  b = row[0]
  m = row[1]
  matrix = []
  for j in range(b):
    matrix.append([False] * b)
    if j != b-1:
      matrix[-1][j+1] = True
  paths = 1
  arr = [0] * (b-1) + [1]
  limits = [2 ** (b-idx-1) for idx, num in enumerate(arr)] + [1]
  del limits[0]
  if m > limits[0]:
    o.write('Case #{}: IMPOSSIBLE\n'.format(i+1))
  else:
    o.write('Case #{}: POSSIBLE\n'.format(i+1))
    j = b-1
    diff = m
    while diff > 0:
      val = min(diff, limits[j])
      arr[j] = val
      diff -= val
      j -= 1
    arr[0] = sum(arr)
    for j, e in enumerate(arr):
      adj = ['0'] * (j+1)
      for k in range(j+1, b):
        if e >= arr[k] and arr[k] != 0:
          adj.append('1')
          e -= arr[k]
        else:
          adj.append('0')
      o.write(''.join(adj))
      o.write('\n')


o.close()
f.close()