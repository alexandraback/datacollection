T = int(raw_input())
for i in range(T):
	N, M, W = [int(j) for j in raw_input().split()]

	ans = 0
	ans = (N-1)*(M/W)
	if N > 1 and M%W != 0:
		ans  += 1
	ans += M/W + W -1
	if M%W != 0:
		ans += 1
	
	print "Case #"+str(i+1)+":", ans
