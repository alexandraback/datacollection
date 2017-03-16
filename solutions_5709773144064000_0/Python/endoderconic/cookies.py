import sys

pattern = "Case #{0}: {1}"


def get_time_n_farm(c,f,x,n):
	return c*sum(1./(2+i*f) for i in xrange(n)) + 1.*x/(2+n*f)

def solve(f):
	c,f,x = [float(i) for i in f.readline().rstrip("\n").split()]
	_min = -1
	n = 0
	while True:
		t = get_time_n_farm(c,f,x,n)
		if t < _min or _min == -1:
			_min = t
		else:
			break
		n += 1
	return "%.7f" %_min


if __name__=="__main__":
	with open(sys.argv[1]) as f:
		ntests = int(f.readline())
		for i in xrange(1,ntests+1):
			t = solve(f)
			print pattern.format(str(i),t)

