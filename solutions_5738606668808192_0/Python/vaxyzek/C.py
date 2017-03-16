import gcj, math

PRIMES = [2, 3, 5]
N = 10000

def divisor(n):
	global PRIMES

	i = 0
	sq = math.ceil(math.sqrt(n))
	while i < len(PRIMES) and PRIMES[i] < sq:
		if n % PRIMES[i] == 0:
			return PRIMES[i]
		i += 1

	return 0

def fill_primes():
	global PRIMES
	for n in range(1, N):
		p = 6 * n + 1
		if divisor(p) == 0:
			PRIMES.append(p)

		p = 6 * n + 5
		if divisor(p) == 0:
			PRIMES.append(p)


def checkjam(C):
	base  = list(range(2, 11))
	power = [1] * 9
	reprs = [0] * 9
	#print(bin(C))
	while C > 0:
		digit = C % 2
		if digit:
			for i in range(9):
				reprs[i] += power[i]
		for i in range(9):
			power[i] *= base[i]
		C //= 2

	
	d = [divisor(r) for r in reprs]
	#print(bin(C), reprs, d)

	if min(d) == 0:
		return []

	return d


fill_primes()
#print(PRIMES)

ifile, ofile = gcj.get_files('C')

T = int(ifile.readline().strip())
for t in range(T):
	N, J = map(int, ifile.readline().strip().split(' '))
	n = 0
	ans = ""
	while J > 0:
		C = (1 << (N - 1)) + (n << 1) + 1
		dividers = checkjam(C)
		if len(dividers):
			J -= 1
			ans += '\n' + bin(C)[2:] + " " + ' '.join(map(str, dividers))
			#print(J)
		n += 1
	gcj.print_answer(ofile, t, ans)