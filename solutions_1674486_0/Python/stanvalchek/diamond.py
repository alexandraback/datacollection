f=open('t.txt','r')
g=open('file.txt','w')

def tester(j):
	global d,s,win
	if j in d and not win:
		for k in d[j]:
			if k in s:
				win=True
			s.add(k)
			tester(k)

for i in range(1,int(f.readline())+1):
	n=int(f.readline())
	d={}
	for j in range(1,1+n):
		for k in f.readline().split()[1:]:
			temp=int(k)
			if not temp in d:
				d[temp]=[]
			d[temp].append(j)
	win=False
	for j in range(n,0,-1):
		if j in d and not win:
			s=set([])
			if len(d[j])>1:
				tester(j)
	if win:
		q='Yes'
	else:
		q='No'
	print 'Case #' + str(i) + ': ' + q
	g.write('Case #' + str(i) + ': ' + q + '\n')
g.close()