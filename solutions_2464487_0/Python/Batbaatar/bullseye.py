import math

def spent(k, r):
	return k * (2 * r + 2 * k - 1)

def search(x, t):
	l = 1
	r = 10**18
	
	while l < r:
		mid = (l + r) / 2
		b = spent(mid, x)
		u = spent(mid + 1, x)
		if(u <= t):
			l = mid + 1
		else:
			if(b > t):
				r = mid
			else:
				return mid
	return -1


def check(r, t):
	for i in range(500):
		if(spent(i, r) <=t and spent(i + 1, r)  > t):
			return i

Q = int(input())

for i in range(Q):
	line = raw_input()
	x = int(line.split(" ")[0])
	y = int(line.split(" ")[1])
	print "Case #" + str(i + 1) + ": " + str(search(x, y))
















