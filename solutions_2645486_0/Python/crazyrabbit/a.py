E = 0
R = 0

def process_sub(V, done, i0, l, hit_left, hit_right):
	global E, R
	max_v = max(V)
	max_i = V.index(max_v)
	H = min(E, (max_i+1) * R)
	if hit_left: H = E
	L = max(0, E - (l-max_i)*R)
	if hit_right: L = 0
	done[i0+max_i] = True
	if H <E: 
		for i in xrange(0,max_i): done[i0+i] = True
	if L >0: 
		for i in xrange(max_i+1,l): done[i0+i] = True
	return  (H-L) * max_v

inf = open('in','r')
T = int(inf.readline())

for c in xrange(T):
	l = inf.readline().split()
	E, R, N = int(l[0]), int(l[1]), int(l[2])

	v = [int(x) for x in inf.readline().split()]
	done = [False] * N

	if E <= R:
		res = E* sum(v)
		print 'Case #' + str(c+1) + ': ' + str(res)
		continue

	res = 0

	while True:
		i0 = 0
		while i0 < N and done[i0]: i0+=1
		if i0 >= N: break
		i1 = i0
		while i1 < N and not done[i1]: i1+=1
		res += process_sub(v[i0:i1], done, i0, i1-i0, i0==0, i1==N)
		
	print 'Case #' + str(c+1) + ': ' + str(res)
	
