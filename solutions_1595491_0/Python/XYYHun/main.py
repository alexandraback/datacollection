# N N N     3N
# N-1 N N   3N-1
# N-1 N-1 N 3N-2
# N-2 N-1 N 3N-3 (*)
# N-2 N-2 N 3N-4 (*)

Input = open('Input','r')
Output = open('Output','w')

for i in xrange(0, int(Input.readline())) :
	params = Input.readline().split(' ')
	N = int(params[0])
	S = int(params[1])
	p = int(params[2])
	ts = [int(m) for m in params[3:]]
	y1 = 0
	y2 = 0
	for t in ts:
	  if t > 3 * p - 3 and t >= p:
	    y1 += 1
	  elif t > 3 * p - 5 and t >= p and y2 < S:
	    y2 += 1
	Output.write('Case #%s: %s\n' % (i + 1, y1 + y2))
