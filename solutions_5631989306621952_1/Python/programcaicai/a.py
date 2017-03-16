n = int(raw_input())
xs = [raw_input() for _ in range(n)]


def solve(x):
	t = x[0]
	for c in x[1:]:
		if ord(c)>=ord(t[0]):
			t = c + t
		else:
			t = t + c
	return t


for i,x in enumerate(xs):
	print 'Case #{}: {}'.format(i+1,solve(x))




