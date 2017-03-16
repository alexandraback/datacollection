
def process(i, o):
	T = int(i.readline())
	for case_num in range(1, T + 1):
		C, F, X = map(float, i.readline().split())
		ans = solve(C, F, X)
		o.write('Case #{}: {:.8f}\n'.format(case_num, ans))
		print 'Case #{}/{}: {:.8f}'.format(case_num, T, ans)
		print

# how long does it take, assuming we build N farms?
def how_long(C, F, X, N):
	return sum(C/(2+n*F) for n in xrange(N)) + X/(2+N*F)


def solve(C, F, X):
	best_N = 0
	best_val = how_long(C, F, X, best_N)
	print '{}->{}'.format(best_N, best_val)

	N = 1
	while N < 5 + int(best_N * 1.2):
		val = how_long(C, F, X, N)
		#print '{}->{}'.format(N, val)
		if val < best_val:
			best_N = N
			best_val = val
		N += 1

	print 'best: {}->{}'.format(best_N, best_val)
	return best_val

	low = 0
	high = 1000000
	
	f_low = how_long(C, F, X, low)
	f_high = how_long(C, F, X, high)

	while high - low >= 2:
		mid = low + (high - low) // 2
		f_mid = how_long(C, F, X, mid)

		if f_high > f_low:
			high = mid
			f_high = f_mid
		else:
			low = mid
			f_low = f_mid

	ords = filter(lambda x: x >= 0, range(low - 2, high + 3))
	fvals = [how_long(C, F, X, n) for n in ords]
	print repr(zip(ords, fvals))
	return min(fvals)


def main():
	cyclename = 'B-small-0'
	with open('source\\{}.in'.format(cyclename), 'rb') as i:
		with open('source\\{}.out'.format(cyclename), 'wb') as o:
			process(i, o)
		

if __name__ == '__main__':
	main()
