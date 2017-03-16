with open("B-small-attempt0.in") as f:
#with open("B-large.in") as f:
#with open("test.in") as f:
	dat = f.read().splitlines()

n = int(dat[0])
out = []
for case in range(1,n+1):
	cod = dat[case].split()[0]
	jam = dat[case].split()[1]
	
	print(cod)
	print(jam)
	
	l = cod.__len__()
	i = 0
	rc = []
	rj = []
	
	while i<l:
		if cod[i] == '?' and jam[i] == '?':
			rc.append(['0','1','9'])
			rj.append(['0','1','9'])
			
		elif cod[i] != '?' and jam[i] != '?':
			rc.append([cod[i]])
			rj.append([jam[i]])
		elif cod[i] != '?':
			rc.append([cod[i]])
			nn = int(cod[i])
			p = list(set([str((nn-1)%10),str(nn%10),str((nn+1)%10),'0','9']))
			rj.append(p)
		else:
			rj.append([jam[i]])
			nn = int(jam[i])
			p = list(set([str((nn-1)%10),str(nn%10),str((nn+1)%10),'0','9']))
			rc.append(p)
		i += 1
	
	import itertools
	c = list(itertools.product(*rc))
	c.sort()
	c = [int("".join(k)) for k in c]
	
	j = list(itertools.product(*rj))
	j.sort()
	j = [int("".join(k)) for k in j]
	
	nc = c.__len__()
	nj = j.__len__()
	
	mn = abs(j[0]-c[0])
	bc = c[0]
	bj = j[0]
	ic = 0
	ij = 0
	while ic<nc and ij<nj:
		d = abs(j[ij]-c[ic])
		if d<mn:
			mn = d
			bc = c[ic]
			bj = j[ij]
		if j[ij]>c[ic]:
			ic += 1
		else:
			ij += 1
			
	bc = str(bc)
	bj = str(bj)
	res = "Case #"+str(case)+": "+"0"*(l-bc.__len__())+bc+" "+"0"*(l-bj.__len__())+str(bj)

	print(res)
	out.append(res)

assert out.__len__() == n
of = open("out.txt","w")
of.write("\n".join(out))
of.close()



