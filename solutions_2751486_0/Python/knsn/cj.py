def f(c):
	if c == "a" or c == "e" or c == "i" or c == "o" or c == "u":
		return True
	return False
t = int(raw_input())
for cases in range(1,t+1):
	S,N = raw_input().split()
	n = int(N)
	counter = 0 
	L = len(S)
	temp = 0 
	for s in range(L):
		for e in range(s,L):
			temp = 0 
			for i in range(s,e+1):
				if f(S[i]):
					temp = 0
				else : 
					temp += 1 
					if temp >= n:
						counter+=1
						break
	print "Case #"+str(cases)+":",counter