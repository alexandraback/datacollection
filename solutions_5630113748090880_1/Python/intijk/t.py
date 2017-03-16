import sys
lines=sys.stdin.readlines()
C=int(lines[0])
p=1
for i in range(1, C+1):
	n=int(lines[p])
	p+=1
	d={}
	for l in range(2*n-1):
		for h in lines[p].strip().split():
			if h in d:
				d[h]=d[h]+1
			else:
				d[h]=1
		p=p+1
	res=[int(key) for key in d if d[key]%2==1]
	res=sorted(res)

	sys.stdout.write("Case #%d:" % i)
	for num in res:
		sys.stdout.write(" %d" % num)
	print ""		


