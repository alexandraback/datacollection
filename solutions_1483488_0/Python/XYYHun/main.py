Input = open('Input','r')
Output = open('Output','w')

for i in xrange(0, int(Input.readline())) :
  params = Input.readline().split(' ')
  A = int(params[0])
  B = int(params[1])
  y = 0
  for j in xrange(A, B + 1):
    ms = set()
    nstr = '%s' % j
    for k in xrange(1, len(nstr)) :
      nstr = nstr[1:] + nstr[:1]
      if A <= int(nstr) <= B and int(nstr) != j:
        ms.add(nstr)
    y += len(ms)

  Output.write('Case #%s: %s\n' % (i + 1, y / 2))
	
