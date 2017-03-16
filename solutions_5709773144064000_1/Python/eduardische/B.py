T = int(input())
for iT in list(range(0,T)):
	lim = input().split()
	C = float(lim[0])
	F = float(lim[1])
	X = float(lim[2])
	tm = 0.0
	R = 2.0
	res = X / R
	while (tm < res):
		tm += C / R
		R += F
		if ((tm + (X / R)) < res):
			res = tm + X / R
	print("Case #" + str(iT+1) + ": " + "{0:.7f}".format(res))
