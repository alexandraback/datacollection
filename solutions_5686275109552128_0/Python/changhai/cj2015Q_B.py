import sys,math,random,time

def eatTime(P):
	P.sort()
	minTime = P[-1]
	wait = {0:0}
	for i in range(len(P)):
		x = P.pop()
		for w in wait:
			t = max(x,w)+wait[w]
			minTime = min(minTime, t)
		if x <= 3: break
		#split x
		wait2 = {}
		maxParts = int(math.sqrt(x))
		for n in range(2,maxParts+1):
			w2 = x//n
			if w2*n != x: w2+=1
			#print "split",x,n,w2
			for w1 in wait:
				w = max(w1,w2)
				s = wait[w1] + n - 1
				if wait2.get(w, s+1) > s:
					wait2[w] = s
		wait = wait2
		#print len(wait), wait, "!!!"
		#print len(wait), "!!!!"
	else:
		for w in wait:
			t = w + wait[w]
			minTime = min(minTime, t)
	return minTime

f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	D = int(f.readline().strip())
	P = [int(a) for a in f.readline().strip().split()]
	if len(P) != D:
		print "ERROR!", D, len(P)
		sys.exit()
	#print time.ctime()
	t = eatTime(P)
	#print time.ctime()
	print >>out, "Case #%d: %d"%(tc, t)