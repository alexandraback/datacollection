cnt, n = 1, int(input())
p10 = [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000]
def cycle(z, lim, cap):
	o = z
	recycled = set()
	for i in range(lim):
		z = (z // 10) + (z % 10) * p10[lim]
		if z > o and z <= cap:
			recycled.add(z)
			
	return len(recycled)
	
while cnt <= n:
	r = 0
	a, b = map(int, input().split())
	digits = len(str(a))
	for i in range(a, b):
		t = cycle(i, digits-1, b)
		r += t
	print('Case #%d: %d' % (cnt, r))
	cnt += 1
