def gao(r, t):
	down = 1
	up = t + 1
	while down < up:
		mid = (down + up) // 2
		if 2 * mid * r + mid + 2 * mid * (mid - 1) > t:
			up = mid
		else:
			down = mid + 1
	return down - 1

if __name__ == '__main__':
	tc = int(raw_input())
	for cc in range(tc):
		r, t = [int(x) for x in raw_input().split()]
		print("Case #%d: %d" % (cc + 1, gao(r, t)))
