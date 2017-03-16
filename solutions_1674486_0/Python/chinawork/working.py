import sys, re, os

parents = {}
def solver(i):
  global parents, values, nvalues
  if (i in parents):
    return list(parents[i])
  else:
    t = list(values[i])
    for k in values[i]:
      t.extend(solver(k))
    parents[i] = list(t)
    return list(parents[i])

N = int(sys.stdin.readline().strip())
for qw in range(1, N+1):
  print 'Case #%d:' % qw,
  values = {}
  nvalues = int(sys.stdin.readline().strip())
  for j in xrange(1, nvalues + 1):
    values[j] = [int(i.strip()) for i in sys.stdin.readline().split()]
    nv = values[j][0]
    if (nv > 0):
      values[j] = values[j][1:]
    else:
      values[j] = []
  parents = {}

  for j in xrange(1, nvalues + 1):
    solver(j)
 # print parents
  flag = False
  for j in parents.keys():
    if (len(values[j]) < 2):
          continue
    # print j
    if (len(set(parents[j])) != len(parents[j])):
      print 'Yes'
      flag = True
      break
  if (flag == False):
    print 'No'
