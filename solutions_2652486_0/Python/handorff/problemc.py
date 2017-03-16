def oddForced(p):
  t = 0
  f = 0
  while (p % 3 == 0):
    p /= 3
    t += 1
  while (p % 5 == 0):
    p /= 5
    f += 1
  return [t, f]

def evenForced(p):
  if p == 6:
    return [0, 3]
  if p == 5:
    return [1, 2]
  return [0, 0]

def forced(p):
  odd = p
  even = 0
  while (odd % 2 == 0):
    odd /= 2
    even += 1
  [a3, a5] = oddForced(odd)
  [a2, a4] = evenForced(even)
  return [0, a3, 0, a5]

def output(l):
  [a2, a3, a4, a5] = l
  return '2' * a2 + '3' * a3 + '4' * a4 + '5' * a5

def fill(m, s, p):
  [a2, a3, a4, a5] = m
  if s == 2:
    if [x for x in p if x % 4 == 0] != []:
      return [0, a3, 1, a5]
    else:
      return [1, a3, 0, a5]
  elif s == 1:
    if [x for x in p if x % 16 == 0] != []:
      return [0, a3, 2, a5]
    if [x for x in p if x % 8 == 0] != []:
      return [1, a3, 1, a5]
    if [x for x in p if x % 4 == 0] != []:
      return [2, a3, 0, a5]
    if [x for x in p if x % 2 == 0] != []:
      return [2, a3, 0, a5]
    return [2, a3, 0, a5]
  else:
    if [x for x in p if x % 64 == 0] != []:
      return [0, a3, 3, a5]
    if [x for x in p if x % 32 == 0] != []:
      return [1, a3, 2, a5]
    if [x for x in p if x % 16 == 0] != []:
      return [2, a3, 1, a5]
    if [x for x in p if x % 8 == 0] != []:
      return [3, a3, 0, a5]
    if [x for x in p if x % 4 == 0] != []:
      return [3, a3, 0, a5]
    if [x for x in p if x % 2 == 0] != []:
      return [2, a3, 1, a5]
    return [2, a3, 1, a5]


infile = open("input.txt", "r")
outfile = open("out.txt", "w")
lines = infile.read().split('\n')
cases = int(lines[0])

outfile.write("Case #1:\n")

for i in xrange(1, cases + 1):
  [r, n, m, k] = map(int, lines[i].split(' '))
  for j in xrange(2, r+2):
    prods = map(int, lines[j].split(' '))
    f = [forced(p) for p in prods]
    f2 = [a[0] for a in f]
    f3 = [a[1] for a in f]
    f4 = [a[2] for a in f]
    f5 = [a[3] for a in f]
    m = [max(f2), max(f3), max(f4), max(f5)]

    if sum(m) == 3:
      outfile.write(output(m) + '\n')
    else:
      m = fill(m, sum(m), prods)
      outfile.write(output(m) + '\n')

infile.close()
outfile.close()
