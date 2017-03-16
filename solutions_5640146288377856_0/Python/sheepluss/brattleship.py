def brattleship_small(row, column, width):
  #if column==width:
  #  return width
  return width + ((column-1)/width)

ncases = int(raw_input().strip())
for i in xrange(1,ncases+1):
  fields = [int(j) for j in raw_input().strip().split(' ')]
  print "Case #{0}: {1}".format(i, brattleship_small(fields[0], fields[1], fields[2]))
