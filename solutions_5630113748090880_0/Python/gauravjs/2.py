def kselect(k, pos, lists):
  l = [i[pos] for i in lists]
  l.sort()
  b = False
  if k < len(lists) - 1:
    if l[k] == l[k+1]:
      b = True
  return l[k], b


with open('B-small-attempt0.in','r') as f:
    cases=int(f.readline())
    lines=f.readlines()

ind = 0

for i in range(cases):
  n = int(lines[ind].strip())
  ind += 1
  lists = []
  for j in range(2 * n - 1):
    lists.append(map(int, lines[ind].strip().split(' ')))
    ind += 1
  
  grid = []

  k = 0
  m = 0

  for j in range(n):
    a, b = kselect(k, j, lists)
    grid.append(a)
    if b:
      k += 2
    else:
      m = k / 2
      k += 1

  mlist = [l for l in lists if l[m] == grid[m]][0]

  mterms = [l[m] for l in lists]
  mterms.sort()

  out = []

  k = 0
  for j in mterms:
    if k < len(mlist) and j == mlist[k]:
      k +=1
    else:
      out.append(j)

  out = out[:m] + [grid[m]] + out[m:]


  print "Case #" + str(i+1) + ": " + ' '.join(map(str, out))
