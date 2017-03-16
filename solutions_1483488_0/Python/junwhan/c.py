import sys

def recycled_pairs(A, B):
  num = 0
  for n in xrange(max(A, 10), B + 1):
    ns = str(n)
    ms = set()
    for i in xrange(1, len(ns)):
      m = int(ns[i:] + ns[:i])
      if len(str(m)) == len(str(n)) and n < m and A <= m <= B and m not in ms:
        num += 1
        ms.add(m)
  return num

with open(sys.argv[1]) as fin:
  with open('output', 'w') as fout:
    for i, line in enumerate(fin):
      if i > 0:
        A, B = map(int, line.split())
        fout.write('Case #%d: %d\n' % (i, recycled_pairs(A, B)))
