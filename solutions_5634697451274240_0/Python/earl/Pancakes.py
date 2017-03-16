TT = int(raw_input())
for tt in range(1, 1 + TT):
  data = raw_input() + '+'
  print 'Case #%d: %d' % (tt, len([0 for a, b in zip(data, data[1:]) if a != b]))
