import sys, time

def main():    
    f = open(sys.argv[1])
    t = int(f.readline().strip())

    for kk in xrange(t):
	line = f.readline().strip()
	sp = line.split()

	p = [[sp[0]], [sp[1]]]
	
	for l in range(len(sp[0])):
	 try:
	    for j in range(2):	
	        if l < len(sp[j]) and sp[j][l] == '?':
		    tmp = []
		    for elem in p[j]:
			for i in xrange(10):
			    tmpsub = ""
			    for sub in elem[:l]:
			        tmpsub += sub
			    tmpsub += str(i)
			    for sub in elem[(l+1):]:
				tmpsub += sub
			    tmp.append(tmpsub)
		    p[j] = tmp
	    #print "round "+str(l)+":"
	    #print p

	    #print ""
	 except:
	    print line
	    sys.exit(1)

	#print p

	bb = [100000, 0]
	for elem in p[0]:
	    elem = int(elem)
	    for sub in p[1]:
		sub = int(sub)
		diff =  abs(elem-sub)
		if len(bb) == 0 or diff < abs(bb[0]-bb[1]):
		    bb[0] = elem
		    bb[1] = sub
		elif diff == abs(bb[0]-bb[1]):
		    if bb[0] > elem or (bb[0] == elem and bb[1] > sub):
			bb[0] = elem
			bb[1] = sub

	while len(str(bb[0])) < len(sp[0]):
	    bb[0] = "0"+str(bb[0])
	while len(str(bb[1])) < len(sp[1]):
	    bb[1] = "0"+str(bb[1])

	print "Case #"+str(kk+1)+": "+str(bb[0])+" "+str(bb[1])

	#time.sleep(5)

    f.close()

if __name__ == "__main__":
    main()
