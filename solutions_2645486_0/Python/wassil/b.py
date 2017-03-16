def maximize(E,R,v,pos,e):
	if pos == len(v)-1: return v[pos]*e
	maximum = 0
	for i in range(e+1):
		value = v[pos]*i+maximize(E,R,v,pos+1,min(E,e-i+R))
		if value>maximum:
			maximum = value
	return maximum

for T in range(int(raw_input())):
	E,R,N = map(int,raw_input().split())
	v = map(int,raw_input().split())
	
	

	result = maximize(E,R,v,0,E)
	print "Case #%d: %d"%(T+1,result)
