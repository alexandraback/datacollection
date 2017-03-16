t = input()
for i in range(t):
	a = raw_input()
	a = a.split()
	x = int(a[0])
	y = int(a[1])

	ans = ""
	if x < 0:
		ans += "EW" * abs(x)
	if x> 0:
		ans += "WE" * abs(x)
	if y < 0:
		ans += "NS" * abs(y)
	if y> 0:
		ans += "SN" * abs(y)

	print "Case #%d: %s" %(i+1, ans)

