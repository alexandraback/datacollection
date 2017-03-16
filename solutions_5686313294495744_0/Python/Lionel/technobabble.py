import sys

def main():
    f = open(sys.argv[1])

    t = int(f.readline().strip())

    for kk in xrange(t):
	n  = int(f.readline().strip())
	#print n
	s = [set(), set()]
	ws = []	
	for ii in xrange(n):
	    line = f.readline().strip()
	    #print line
	    sp = line.split()
	    s[0].add(sp[0])
	    s[1].add(sp[1])
	    ws.append(sp[0]+":"+sp[1])
	
	ts = [set(), set()]
	os = set()
	ps = set()
	rs = set()
	for elem in ws:
	    sp = elem.split(":")
	    fc = 0
	    if sp[0] in ts[0]: 
		fc += 1
	    if sp[1] in ts[1]:
		fc += 1
	    if fc == 0:
		ts[0].add(sp[0])
		ts[1].add(sp[1])
		os.add(elem)
	    elif fc == 1:
		ts[0].add(sp[0])
                ts[1].add(sp[1])
                ps.add(elem)
	    else:
		rs.add(elem)

	res = n-len(os)-len(ps)

	print "Case #"+str(kk+1)+": "+str(res)
    f.close()

if __name__ == "__main__":
    main()
