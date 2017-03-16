from sys import stdin

global param
class param:
  pass

def doit(i, x):
  if param.J == 0:
    return
  if i == param.N:
    y = [None] * 11
    for j in range(2,11):
      for k in range(2, min(x[j],1000)):
        if x[j]%k == 0:
          y[j] = str(k)
          break
      if not y[j]: return
    print ' '.join([str(x[10])] + y[2:11])
    param.J -= 1
    return

  for b in range(2,11): x[b] = x[b] * b
  if i != 0 and i != param.N-1:
    doit(i+1, x)
  for b in range(2,11): x[b] += 1
  doit(i+1, x)
  for b in range(2,11): x[b] /= b

T = int(stdin.readline())
prob = 1
for i in range(0,T):
  print 'Case #%d:' % prob
  prob += 1
  line = stdin.readline().split()
  param.N = int(line[0]); param.J = int(line[1])

  doit(0, [0L] * 11)
