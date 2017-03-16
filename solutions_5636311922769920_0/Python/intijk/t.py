import sys
lines=sys.stdin.readlines();
n=int(lines[0])
for case in range(1, n+1):
	l=lines[case].split();	
	K=int(l[0])
	C=int(l[1])
	S=int(l[2])
	total_length=K**C
	seg_length=total_length/K
	r=[1]
	for i in range(K-1):
		r.append(r[-1]+seg_length)
	sys.stdout.write("Case #%d:" % (case))
	for e in r:
		sys.stdout.write(" %d" % e)
	print ""
