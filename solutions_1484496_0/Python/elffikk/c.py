lines = open('C-small-attempt0.in').read().split('\n')
T = int(lines[0])
output = []
for t in xrange(1, T+1):
	a = [int(x) for x in lines[t].split()]
	N = a[0]
	a=a[1:]
	a.sort()
	d = dict()
	a1,a2=[],[]
	for x in a:	
		found = False
		#iterate existing keys(sums)		
		for y in d.keys():
			if d.has_key(x+y):
				a1, a2, found = d[x+y], d[y]+[x], True
				found = True
				break
			else:
				d[x+y] = d[y]+[x]
		#should be after iterating keys
		if d.has_key(x):
			a1,a2, found =  d[x], [x], True
			break
		else:
			d[x] = [x]
		if found:
			break
	#print d
	if not a1:
		output.append("Case #"+str(t)+": Impossible")
	else:
		output.append("Case #"+str(t)+":")
		output.append(" ".join([str(x) for x in a1]))
		output.append(" ".join([str(x) for x in a2]))
#print output
open("c.out", "w").write("\n".join(output))