from math import ceil

fin=open('D-small-attempt0.in','r')
T=int(fin.readline())
# T = 5
# inp = ['2 3 2','1 1 1','2 1 1','2 1 2','3 2 3']

file('D-small-attempt0.out','w')
f=open('D-small-attempt0.out','w')

def get_locs(K,C):
	pos = range(K)
	locs = []
	while pos:
		# print pos
		loc = 0
		for i in xrange(min(C,K)):
			if pos:
				loc += pos.pop() * K**i
		locs.append(str(loc+1))
	return locs

for time in xrange(T):
	K, C, S = map(int,fin.readline().strip().split(' '))

	if ceil(K/float(C)) > S:
		# print 'Case #'+str(time+1)+': IMPOSSIBLE\n'
		f.write('Case #'+str(time+1)+': IMPOSSIBLE\n')
	else:
		locs = get_locs(K,C)
		# print 'Case #'+str(time+1)+': '+' '.join(locs)+'\n'
		f.write('Case #'+str(time+1)+': '+' '.join(locs)+'\n')

f.close()