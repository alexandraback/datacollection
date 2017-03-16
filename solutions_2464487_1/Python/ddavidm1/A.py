T=input()
for ic in range(T):
	S=raw_input().split()
	r=long(S[0])
	t=long(S[1])
	inf=1
	sup=1000000000000000000000
	while(sup-inf > 1):
		n=(inf+sup)/2
		test = ((n*(2*r+1))+(2*n*(n-1)))
		if ( test <= t):
			inf=n
		else:
			sup=n
	final_test=((sup*(2*r+1))+(2*sup*(sup-1)))
	if(final_test <= t):
		final_test=sup
	else:
		final_test=inf
	print "Case #" + str(ic+1) + ": " + str(final_test)
