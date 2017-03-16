f = open("B-small-attempt2.in")
fo = open("B-small-attempt000.out", "wb")
T = int(f.readline())
ans = 0
g = []
cars = []
n = 0
bigflag = True

def check(his):
    h = {x:False for x in "abcdefghijklmnopqrstuvwxyz"}
    for i in range(len(his)):
        if i and his[i] != his[i-1]:
            if h[his[i]]: return False
        h[his[i]] = True
    return True

def dfs(cur, his):
    global ans, g, cars, n, bigflag, jc
    if not check(his): return
    if cur == n:
	ans += 1

    flag = True
    for i in xrange(n):
        if g[i] and (not his or his[-1] == cars[i][0]):
	    if his:
	    	if not flag:
			bigflag = False
			return
	    	flag = False
            g[i] = False
            dfs(cur + 1, his + cars[i])
            g[i] = True
    if not his or not flag: return
    ans += jc[n-cur]


for i in range(T):
    ti = i
    line = f.readline()
    n = int(line)
    ans = 0
    cars = f.readline().split()
    newcars = []
    for x in cars:
	ns = []
	for j in range(len(x)):
	    if not j or x[j] != x[j-1]:
		ns.append(x[j])
	newcars.append("".join(ns))
	
    hh = {x:False for x in "abcdefghijklmnopqrstuvwxyz"}
    
    cars = []
    for x in newcars:
	if len(x)>2:
	   for j in range(1, len(x)-1):
	       if hh[x[j]]: ans = -1
	       else: hh[x[j]] = True
	   cars.append(x[0] + x[-1])
	else:
	   cars.append(x)
    if ans == -1:
        fo.write("Case #%d: 0\n" % (i+1))
        continue

    cnt = {x:0 for x in "abcdefghijklmnopqrstuvwxyz"}
    acars = [x for x in cars if len(x) == 1]
    for x in acars:
	cnt[x] += 1
    acars = list(set(acars))
    bcars = [x for x in cars if len(x) == 2]
    for i in range(len(acars)):
	x = acars[i]
	for y in bcars:
	    if y[0] == x or y[1] == x:
		acars[i] = ""
    for x in range(len(bcars)):
	if bcars[x]:
	    for y in range(x+1, len(bcars)):
		if bcars[x] and bcars[y] and bcars[x][1] == bcars[y][0]:
		    ncar = bcars[x][0] + bcars[y][1]
		    bcars[y] = ncar
		    bcars[x] = ""
		elif bcars[x] and bcars[y] and bcars[x][0] == bcars[y][1]:
		    ncar = bcars[y][0] + bcars[x][1]
		    bcars[y] = ncar
		    bcars[x] = ""
    bcars = [x for x in bcars if x]

    cars = bcars + [x for x in acars if x]
    jc = [1 for m in range(11)]
    for x in range(1,11): jc[x] = jc[x-1] * x
    print cars

    n = len(cars)
    g = [True for j in range(n)]
    if n == 1: ans = 1
    else: dfs(0, "")
    for x in "abcdefghijklmnopqrstuvwxyz":
	ans *= jc[cnt[x]]
    if not bigflag: ans = 0
    print ans
    fo.write("Case #%d: %d\n" % (ti+1, ans))



 
