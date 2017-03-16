def rank_and_file(lists):
  table = {}
  for row in lists:
    for soldier in row:
      if soldier not in table:
        table[soldier] = 0

      table[soldier] += 1

  missing = []
  for soldier, count in table.iteritems():
    if count % 2 == 1:
      missing.append(soldier)

  return ' '.join(map(lambda x: str(x), sorted(map(lambda x: int(x), missing))))

filename = 'B-large'
f = open(filename + '.in', 'r')
o = open(filename + '.out', 'w')

T = int(f.readline())

for t in range(T):
  N = int(f.readline())
  lists = []
  for i in xrange(2*N-1):
    lists.append(f.readline().split())
  o.write('Case #%d: %s\n' % (t + 1, rank_and_file(lists)))
