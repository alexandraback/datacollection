from sys import stdin


T = int(stdin.readline())
for i in range(0,T):
	ls = stdin.readline().split(" ")
	b = int(ls[0])
	a = int(ls[1])
	astr = "SN"
	bstr = "WE"
	if a < 0:
		a = -a
		astr = "NS"
	if b < 0:
		b = -b
		bstr = "EW"
	res = astr*a + bstr*b
	print "Case #{0}: {1}".format(i+1, res)
