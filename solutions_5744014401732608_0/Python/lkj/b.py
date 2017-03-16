import itertools

def getcn(adjm):
	b = len(adjm[0])
	cn = [0]*b
	cn[0] = 1
	for i in range(1,b):
		cn[i] = sum([cn[j] for j in range(0,i) if adjm[j][i] == '1'])
	return cn[b-1]


def tryall(b,m):
	pd = dict()
	nn = sum([x for x in range(0,b)])
	for adjme in range(2**nn):
		adjme = bin(adjme)[2:]
		adjme = '0'*(nn-len(adjme))+adjme
		adjm = []
		for i in range(b):
			con = ''.join(adjme[:b-i-1])
			adjme = adjme[b-i-1:]
			adjm.append('0'*(i+1)+con)
		#print(adjm)
		connum = getcn(adjm)
		if connum > 0:
			if connum not in pd:
				pd[connum] = adjm
	return pd
		

def solve(b,m):
	if m == 1:
		mat = ['0'*b for i in range(b)]
		mat[0] = mat[0][:-1] + '1'
		return ('POSSIBLE', mat)
	if m > 2**(b-2):
		return ('IMPOSSIBLE',[])
	#d = tryall(b,0)
	return ('POSSIBLE', precd[b][m])
	#z = 2**(b-2)-m
	#s = bin(z)[2:]
	#s = s.replace('0','2').replace('1','0').replace('2','1')
	#s = '0'+s+'1'
	#mat = [s]
	#for i in range(1,b):
		#mat.append((i+1)*'0' + (b-i-1)*'1')
	#assert(getcn(mat) == m)
	#return ('POSSIBLE', mat)

precd = [0,0] + [tryall(i,0) for i in range(2,7)]
tc = int(input())
for t in range(1,tc+1):
	b,m = [int(x) for x in input().split()]
	sol = solve(b,m)
	print('Case #{}: {}'.format(t,sol[0]))
	if sol[0] == 'POSSIBLE':
		for l in sol[1]:
			print(l)
