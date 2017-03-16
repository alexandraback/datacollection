f = open("D-small-attempt2.in", "r")
#f = open("data.txt", "r")
g = open("answer.txt", "w")

T = int(f.readline())
N = 0
start = []
numchest = {}
numkeys = {}
lock = {}
keep = []

def bad():
	g.write("IMPOSSIBLE\n")
	return False

def canDFS():
	vst = {key:False for key in lock.keys()}
	stack = []
	for s in start:
		stack = []
		stack.append(s)
		while len(stack)>0:
			t = stack.pop()
			if vst[t]: continue
			vst[t] = True
			for y in lock[t]:
				stack.extend(y[0])
	for i in vst: 
		if not vst[i]: return False
	return True


def DFS():
	curr = start[:]
	while len(curr)>0:
		t = curr.pop()
		if numchest[t]==0: continue
		numchest[t] -= 1
		l = lock[t].pop()
		curr.extend(l[0])
		g.write(str(l[1])+" ")
		keep.append(l[1])
	g.write("\n")

for mm in range(T):
	keep = []
	g.write("Case #{}: ".format(mm+1))
	K, N = map(int, f.readline().split())
	start = map(int, f.readline().split())
	lock = {}
	for i in range(N):
		x = map(int, f.readline().split())
		if x[0] not in lock.keys(): lock[x[0]] = [[x[1:], i+1]]
		else: lock[x[0]].append([x[1:], i+1])
	for z in lock.keys():
		for y in lock[z]:
			y[0] = filter(lambda x: x in lock.keys(), y[0])
	numchest = {key:len(lock[key]) for key in lock.keys()}
	numkeys = {key:0 for key in lock.keys()}
	for z in lock.keys():
		for y in lock[z]:
			for t in y[0]:
				numkeys[t] += 1
	start = filter(lambda x: x in lock.keys(), start)
	startset = {key:0 for key in lock.keys()}
	for x in start:
		startset[x] += 1
	
	can = True
	for i in lock.keys():
		if startset[i]+numkeys[i]<numchest[i]:
			can = bad()
			break
	if not can: continue
	if not canDFS():
		bad()
		continue
	
	for i in lock.keys():
		dec = [(i in x[0], k, x) for k, x in enumerate(lock[i])]
		dec.sort()
		lock[i] = [x[2] for x in dec]
	DFS()


f.close()
g.close()
