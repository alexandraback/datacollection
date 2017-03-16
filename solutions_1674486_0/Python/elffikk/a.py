import copy

def check(dd, v):
	d = copy.deepcopy(dd)
	visits = dict()
	n = len(d)
	for i in xrange(1, n+1):
		visits[i]=0
	a = [v]
	for i in xrange(1, n+1):
		a1 = []
		for x in a:
			a1+=d[x]
		for x in a1:
			visits[x]+=1			
		a = a1[:]
		#print a
	for k,v in visits.iteritems():
		if v>1:
			return True
	return False

lines = open('A-small-attempt0.in').read().split('\n')
T = int(lines[0])
k = 1
output = []
for t in xrange(1, T+1):
	N, k = int(lines[k]), k+1
	d = {}
	for i in xrange(1, N+1):
		d[i] = [int(x) for x in lines[k].split()][1:]
		k+=1
		#print d[i]
	r = 'No'
	for i in xrange(1, N+1):
		if check(d, i):
			r = 'Yes'
			break
	output.append("Case #"+str(t)+": "+r)
open("a.out", "w").write("\n".join(output))