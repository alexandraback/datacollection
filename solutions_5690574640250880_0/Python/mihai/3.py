
def gcj3(numrows, numcols, numbombs):
  if numrows * numcols == numbombs + 1:
    for i in xrange(numrows):
        line = [] if i != 0 else ['c']
        line += ['*' for x in xrange(numcols - len(line))]
        print ''.join(line)
    return
  
  if numrows == 1:
    line = ['c']
    line += ['.' for x in xrange(numcols - numbombs - 1)]
    line += ['*' for x in xrange(numbombs)]
    print ''.join(line)
    return
    
  if numcols == 1:
    print 'c'
    for x in xrange(numrows - numbombs - 1):
      print '.'
    for x in xrange(numbombs):
      print '*'
    return
    
  allcomb = [[]]
  for row in xrange(0, numrows-1):
    oldcomb = allcomb
    allcomb = []
  
    for comb in oldcomb:
      oldmax = comb[-1] if comb else numcols
      for col in xrange(2, oldmax+1):
        allcomb.append(comb + [col])
      allcomb.append(comb + [0])

  for l in allcomb:
    l.insert(0, l[0])

  for comb in allcomb:
    mapsize = numrows * numcols
    numclean = sum(comb)
    bombs = mapsize - numclean

    if numbombs != bombs:
      continue
    
    for i, row in enumerate(comb):
      line = []
      if i == 0:
          line.append('c')
          row -= 1
      line += ['.' for x in xrange(row)]
      line += ['*' for x in xrange(numcols - len(line))]
     
      print ''.join(line)
    
    return 
  
  print 'Impossible'

inf = open('3.in')
numtests = int(inf.readline())

for testindex in xrange(numtests):
  r,c,m = tuple([int(x) for x in inf.readline().split(' ')])

  print 'Case #{0}:'.format(testindex+1)
  gcj3(r,c,m)
