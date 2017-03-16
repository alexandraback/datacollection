for t in range(int(input())) :
	n = int(input())
	if n==0 :
		print("Case #%d: INSOMNIA" % (t+1))
		continue
	x = n
	dig = set(list(str(x)))
	while len(dig) != 10 :
		x += n
		dig.update(list(str(x)))
	print("Case #%d: %d" % (t+1,x))
