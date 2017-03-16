import sys

def fun(c, f, x):
	opt = 0
	opt_time = x / 2.0
	opt_btime = 0.0
	while True:
		new_btime = opt_btime + c / (2.0 + opt * f)
		new_time = new_btime + x / (2.0 + opt * f + f)
		if new_time < opt_time:
			opt += 1
			opt_btime = new_btime
			opt_time = new_time
		else:
			break
	return opt_time

tc = int(sys.stdin.readline())
for t in range(tc):
	s = sys.stdin.readline().split()
	C = float(s[0])
	F = float(s[1])
	X = float(s[2])
	print 'Case #%d: %.10f' % (t+1, fun(C, F, X))
