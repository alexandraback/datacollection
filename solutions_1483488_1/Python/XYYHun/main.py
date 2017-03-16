Input = open('Input','r')
Output = open('Output','w')

for i in xrange(0, int(Input.readline())) :
  params = Input.readline().split(' ')
  A = int(params[0])
  B = int(params[1])
  y = 0
  for n in xrange(A, B + 1):
    ms = set()        # match set
    nstr = '%s' % n   # string of n
    mstr = nstr       # string to match
    for k in xrange(1, len(nstr)) :
      mstr = mstr[1:] + mstr[:1]
      if nstr < mstr <= '%s' % B:
        ms.add(mstr)
    y += len(ms)
  print "#%s is Done" % (i + 1)

  Output.write('Case #%s: %s\n' % (i + 1, y))
	
