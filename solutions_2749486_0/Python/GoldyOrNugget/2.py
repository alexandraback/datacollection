LIM = 30

seen = set()
# seen[(x,y,num_moves)] is boolean

comb = {}
# pos[(x,y)] is boolean

def go(x, y, moves, seq):
	if moves > LIM:
		return
	js = moves + 1
	if (x,y,moves) in seen:
		return
	seen.add((x,y,moves))
	comb[(x,y)] = seq

	go(x+js, y, moves+1, seq+['E'])
	go(x-js, y, moves+1, seq+['W'])
	go(x, y+js, moves+1, seq+['N'])
	go(x, y-js, moves+1, seq+['S'])

go(0,0,0,[])

#for x in xrange(-100, 101):
#	for y in xrange(-100, 101):
#		assert (x,y) in comb

f = open('in.txt')
n = int(f.readline())
for i in xrange(n):
	x, y = map(int, f.readline().split())
	print 'Case #%d: %s' % (i+1, ''.join(comb[(x,y)]))
	#print ('Case #%d' % i+1)# + ''.join(comb[(x, y)])

#print len(comb.keys())