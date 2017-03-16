T = input()

DP = [0]

for i in range(20):
	DP.append(i+1)
	
for tc in range(T):

	N = input()
	if len(DP) <= N:
		i = len(DP);
		while i <= N:
			DP.append(DP[i-1] + 1)
			if i % 10 != 0:		
				rev = int(str(i)[::-1])
				if rev < i:
					DP[i] = min(DP[i], DP[rev] + 1)
			i+=1
				
	print "Case #%d: %d" % (tc+1, DP[N])
	
	
