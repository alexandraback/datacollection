import copy,sys
from sets import Set
lines=sys.stdin.readlines()
C=int(lines[0])
pos=1
for c in range(1,C+1):
	n = int(lines[pos])
	pos+=1
	f=[int(t)-1 for t in lines[pos].strip().split()]
	pos+=1

	# fl[i] is the list of people who love i
	fl=[[] for x in range(n)]
	for i in range(len(f)):
		fl[f[i]].append(i)
	wl=copy.deepcopy(fl)
	#print f
	#print wl
	#rs is people who no one love
	rs=[]
	for i in range(len(fl)):
		if len(fl[i])==0:
			rs.append(i)

	while len(rs)>0:
		to=rs[-1]
		rs.pop()
		wl[f[to]].remove(to)
		if len(wl[f[to]])==0:
			rs.append(f[to])

	max_circle_length=0	
	for i in range(len(wl)):
		s=Set([])
		if len(wl[i])>0:	
			j=i
			while f[j] not in s:
				s.add(f[j])
				wl[f[j]].remove(j)
				j=f[j]
			max_circle_length=max(max_circle_length, len(s))

	cores=[]
	for i in range(n):
		for j in range(i+1,n):
			if f[i]==j and f[j]==i:
				cores.append([i,j])
	coreends={}
	for p in cores:
		coreends[p[0]]=0
		coreends[p[1]]=0
			
	wl=copy.deepcopy(fl)
	rs=[]
	for i in range(len(fl)):
		if len(fl[i])==0:
			rs.append(i)
	length=1
	while len(rs)>0:
		to=rs[-1]
		rs.pop()
		wl[f[to]].remove(to)
		if len(wl[f[to]])==0:
			length=length+1
			rs.append(f[to])
		else:
			if f[to] in coreends:
				coreends[f[to]]=max(coreends[f[to]], length)
			length=1
	
	linklen=[]
	for pair in cores:
		linklen.append(coreends[pair[0]]+coreends[pair[1]]+2)
	#print linklen
	linktlen=sum(linklen)		

	#print "linktlen", linktlen
	res=max(linktlen, max_circle_length)
	print "Case #%d: %d" % (c, res)

