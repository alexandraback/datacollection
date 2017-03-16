def f(c):
	if c == "a" or c == "e" or c == "i" or c == "o" or c == "u":
		return False
	return True
t = int(raw_input())
for cases in range(1,t+1):
	arr,N = raw_input().split()
	n = int(N)
	counter = 0 
	L = len(arr)
	S,s,e = 0,0,0
	
	while s<L and e<L:
		if f(arr[s]) and f(arr[e]):
			e += 1
		elif f(arr[e]) == False: 
			s,e = e+1,e+1
			continue
		if e - s >= n: 
			counter += (s-S+1)*(L-e+1)
			S,s = s+1,s+1 
	
	
	print "Case #"+str(cases)+":",counter