d = {}
def rek(x,y):
	#print x,y
	if("?" in x):
		return [rek(x.replace("?", str(i),1),y) for i in range(0,10)] 

	if("?" in y):
		return [rek(x,y.replace("?", str(j),1)) for j in range(0,10)]

	#print x,y
	raz = abs(int(x)-int(y))
	if(raz in d.keys()):
		tc,tj = d[raz]
		if(tc > x):
			d[abs(int(x)-int(y))] = (x,y)
		elif(tc == x and tj > y):
			d[abs(int(x)-int(y))] = (x,y)

	else:
		d[abs(int(x)-int(y))] = (x,y)
	return 0


n = int(raw_input())
md = 10**18 
for da in range(n):
	c,j = raw_input().split()
	rek(c,j)
	#print "-------------"

	#print d
	rc, rj = d[sorted(d.keys())[0]]
	print "Case #{0}: {1} {2}".format(da + 1, rc, rj)
	#print d
	d = {}

