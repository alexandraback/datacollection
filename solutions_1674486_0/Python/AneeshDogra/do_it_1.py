import sys
import itertools

def inherits_from(c, index):
	res = []
	for a in c[int(index)]:
		if c[int(a)] == []:
			res += [int(a)]
			#print res , ' -- limiting'
		else:
			#print res, ' -- Calling '
			res += [int(a)] + inherits_from(c, int(a))		
	return res

for tc in xrange(1, int(sys.stdin.readline())+1):
  n = int(sys.stdin.readline())
  classes = {}
  msg = ''
  for i in xrange(0, n):
   try:
	c = sys.stdin.readline().split()[1:]
   except IndexError:
	classes[i+1] = []
   classes[i+1] = c
  #print '\n' , str(classes)
  for x in classes:
  	graph = inherits_from(classes, x)
  	for i in graph:
	 if graph.count(i) > 1:
		msg = 'Case #%d: Yes' % tc
		break
	if graph.count(i) > 1:
		break
		
  if msg == '':
	msg = 'Case #%d: No' % tc
  #print classes
  #print graph
  print msg