winner = []

def mines(cur,height,sofar,tot,target):
	global winner
	if winner:
		return
	if cur<2:
		return
	if tot>target:
		return
	if tot == target:
		winner = sofar
		return
	if len(sofar)==height:
		return
	if not sofar:
		mines(cur,height,sofar+[cur,cur],tot+2*cur,target)
	else:
		mines(cur,height,sofar+[cur],tot+cur,target)
	mines(cur-1,height,sofar,tot,target)
	
f=open('temp.txt','rb')
g=open('submit.txt','wb')
for i in range(int(f.readline().strip())):
	g.write('Case #' + str(i+1) +':\n')
	winner = []
	ret = []
	flip = False
	z = f.readline().strip().split()
	[r,c,m] = map(int,z)
	if r>c:
		flip = True
		[c,r]=[r,c]
	mines(r,c,[],0,r*c-m)
	if r*c - m == 1:
		ret =[['*' for k in range(r)] for j in range(c)]
	elif r==1:
		for j in range(c-m):
			ret.append(['.'])
		for j in range(m):
			ret.append(['*'])
	else:
		if not winner:
			g.write('Impossible\n')
		else:
			for j in winner:
				ret.append(['.' for k in range(j)]+[ '*' for k in range (r-j)])
			for j in range(c-len(winner)):
				ret.append(['*' for k in range(r)])
	if winner or r==1 or (r*c-m == 1):
		ret[0][0] = 'c' + ret[0][0][1:]
	if not flip:
		ret = zip(*ret)
	for j in ret:
		g.write(''.join(j) +'\n')
g.close()
	
	
	