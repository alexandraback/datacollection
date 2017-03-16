
d = {}

for k in xrange(1, 101):
  d[k] = {}
  d[k][1] = range(1, k+1)

  for c in xrange(2, 101):
    d[k][c] = []

    i = 0
    while i*c < k:
      s = range(1, k+1)[i*c:(i+1)*c]
      while len(s) < c:
        s.append(1)

      v = 1
      for val in s:
        v = (v - 1) * k + val
      d[k][c].append(v)

      i += 1


fin = open('D-small-attempt0.in', 'r')
lines = fin.readlines()
fout = open('out.txt', 'w')

T = int(lines[0].strip())
for t in xrange(1, T+1):
  line = lines[t]
  arr = line.strip().split(' ')

  K = int(arr[0])
  C = int(arr[1])
  S = int(arr[2])

  if float(K) / S > S:
    fout.write('Case #%d: IMPOSSIBLE\n' % t)
  else:
    fout.write('Case #%d:' % t)
    for v in d[K][C]:
      fout.write(' ' + str(v))
    fout.write('\n')

