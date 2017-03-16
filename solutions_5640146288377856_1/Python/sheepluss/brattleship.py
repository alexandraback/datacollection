def brattleship_small(row, column, width):
  #if column==width:
  #  return width
  return width + ((column-1)/width)

def brattleship(row, column, width):
  base = column/width
  left = column%width
  if left==0:
    return row*base + width-1
  return row*base + width
ncases = int(raw_input().strip())
for i in xrange(1,ncases+1):
  fields = [int(j) for j in raw_input().strip().split(' ')]
  print "Case #{0}: {1}".format(i, brattleship(fields[0], fields[1], fields[2]))
