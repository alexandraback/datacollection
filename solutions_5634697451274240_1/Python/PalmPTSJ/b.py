for t in range(int(input())) :
	x = input()
	ans = 0
	while '-' in x :
		# flip as far as we can
		if '+' not in x :
			ans += 1
			break
		ind = 0
		while x[ind+1] == x[ind] :
			ind+=1
		flipChar = "-+"[x[0] == '-']
		x = flipChar*(ind+1) + x[ind+1:]
		ans += 1
		#print(x)
	print("Case #%d: %d" % (t+1,ans))
	