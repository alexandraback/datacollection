import string

fn = "A-large.in"

f= open(fn,'r')



tcase = int(f.readline())

for tc in xrange(tcase):
	line = f.readline()
	#print line
	linedata = line.split()
	n = int(linedata[0])
	#print n
	jp = []
	total = 0
	for d in xrange(n):
		#print d
		jp.append(int(linedata[d+1]))
		total += jp[d]
	
	restcomp = 0
	resttotal = 0
	for d in xrange(n):
		if jp[d] <= 2*float(total)/float(n):
			restcomp += 1
			resttotal += jp[d]
	
	resttotal += total
	result = ""
	for d in xrange(n):
		if jp[d] <= 2*float(total)/float(n):
			p = (1/float(restcomp) * resttotal - jp[d] ) / float(total)
		else:
			p = 0
		p = max( 0 , p )
		result = result +" "+ str(p*100)
	
	print "Case #%d:"%(tc+1)+result


