def f( steps ):
	tot = 0;
	proc_per_sec = 2.0;

	while 1:
		#print steps
		if steps == 0:
			tot += ( ( X) / (proc_per_sec) )
			return ( tot )
		else:
			tot += ((C) / (proc_per_sec) )
			proc_per_sec += (F)
		steps = steps - 1

	return ( tot )

def bsearch( C, F, X ):
	lo = 0
	hi = 2500000

	while lo <= hi:
		mid = ( lo + hi ) / 2
		#print "%lf %lf" % (f(mid) , f(mid+1))
		if f(mid) > f(mid+1):
			lo = mid+1;
		else:
			hi = mid-1;
	
	return ( f(lo) )

tests = int(raw_input())

for i in range( 1, tests+1 ):
	x = raw_input().split( " " )
	C = float(x[0])
	F = float(x[1])
	X = float(x[2])
	print "Case #%d: %.7lf" % ( i, bsearch(C,F,X) )
