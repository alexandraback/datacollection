for T in range(int(raw_input())):
	r,t = map(int, raw_input().split())
	i = 0
	while t>=2*(r+(2*i+1))-1:
		t-=2*(r+(2*i+1))-1
		i+=1

	result = i
	print "Case #%d: %d"%(T+1,result)
