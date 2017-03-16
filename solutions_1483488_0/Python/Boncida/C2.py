import sys

m={}
r={}
for dig in range(1,8) :
    m[dig] = {}
    r[dig] = {}
    for i in xrange(1,min(10**dig,2000000)) :
	md = i%10
	j = i/10+md*(10**(dig-1))
	m[dig][i] = j
#	r[dig][j] = i

sys.stderr.write("Kesz\n")

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    a,b = map(int,sys.stdin.readline().split())
    dig = len(str(a))
    tc = set(range(a,b+1))
    output = 0
    while len(tc)>0 :
	e = tc.pop()
	start = e
	v = [e]
	length = 0
	while True :
	    length += 1
	    ee = m[dig][e]
	    tc.discard(ee)
	    if ee==start :
		break
	    e = ee
	    v.append(e)
	    
	cnt = 0
	for e in v :
	    if a<=e<=b :
		cnt += 1
	output += cnt*(cnt-1)/2
    print "Case #"+str(testNr)+": "+str(output)
