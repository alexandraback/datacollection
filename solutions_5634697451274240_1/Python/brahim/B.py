import sys

t = int(sys.stdin.readline())
for test in range(t):
  line = sys.stdin.readline().strip()
  l = [line[c] for c in range(len(line))]
  res = -1
  while len(l) > 0:
    res += 1
    while len(l) > 0 and l[-1] == '+':
      del l[-1]
    for i in range(len(l)):
      if l[i] == '+':
        l[i] = '-'
      else:
        l[i] = '+'
  print 'Case #{}: {}'.format(test+1, res)
