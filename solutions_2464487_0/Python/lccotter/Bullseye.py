def main():	
	global pl
	T=input()
	for c in xrange(T):
		r, t = map(int, raw_input().split())
		n=0
		while t>0:
			t= t - (r+2*n)*2 - 1
			if t>=0:
				n+=1
		print "Case #%d: %d" % (c+1, n)

main()