for case in range(1, int(input())+1):
	(B,M) = list(map(int,input().split()))
	result = M<=((1<<(B-1))-1)
	if result:
		print("Case #%d: %s" % (case,"POSSIBLE"))
		for i in range(B-1):
			if (M % 2) == 1:
				conn = "1"
			else:
				conn = "0"
			M = M >> 1
			print(("0"*(i+1))+"1"*(B-i-2)+conn)
		print("0"*B)
	else:
		print("Case #%d: %s" % (case,"IMPOSSIBLE"))
		

