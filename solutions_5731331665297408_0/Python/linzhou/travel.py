from sets import Set
edges = {}
zcode = []

def findsmall(arrvd,sorta,stack,s):
	global edges,zcode
	#print arrvd,stack,s
	if (len(arrvd) == len(sorta)):
		return s

	for j in range(0,len(sorta)):
		dst = sorta[j] + 1
		if (dst in arrvd):
			continue
		ls = len(stack)
		for k in range(0,ls):
			if (dst in edges[stack[ls-1-k]]):
				arrvd.add(dst)
				newstack = stack[:ls-k]
				newstack.append(dst)
				news = s + str(zcode[dst-1])
				rets = findsmall(arrvd,sorta,newstack,news)
				if (len(rets) == 5 * len(zcode)):
					return rets

				arrvd.remove(dst)

	return s
linearray = []

fp = open('C-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('output.txt','w')
t = 0
i = 1
while (t < T):
	splits = linearray[i].split()
	N = int(splits[0])
	M = int(splits[1])
	i += 1
	t += 1

	zcode = []
	edges = {}
	for j in range(0,N):
		zcode.append(int(linearray[i]))
		i += 1
		edges[j+1] = Set([])

	for j in range(0,M):
		splits = linearray[i].split()
		a = int(splits[0])
		b = int(splits[1])
		edges[a].add(b)
		edges[b].add(a)
		i += 1

	sorta = []
	for j in range(0,N):
		idx = -1
		v = 100000
		for k in range(0,N):
			if (not k in sorta and zcode[k] < v):
				v = zcode[k]
				idx = k
		sorta.append(idx)
	#print sorta,"-------------"
	s = ""

	arrvd = Set([])
	stack = []
	for j in range(0,N):
		stack.append(sorta[j]+1)
		arrvd.add(sorta[j]+1)
		s = findsmall(arrvd,sorta,stack,str(zcode[sorta[j]]))
		if (len(s) == 5 * N):
			break
	op.write("Case #%s: %s\n" % (t,s))
op.close()