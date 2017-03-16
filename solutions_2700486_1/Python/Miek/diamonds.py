import sys

def choose(n, k):
    """
    A fast way to calculate binomial coefficients by Andrew Dalke (contrib).
    """
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in xrange(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

def structure(n):
	if n == 0:
		return 0

	if n == 1:
		return 1

	return (n * (2 + (n - 1) * 4)) / 2

def prob(n, x, y):
	if x == 0 and y == 0 and n > 0:
		return 1.0

	width = long((abs(x) + y) / 2)
	#print
	#print '\t', n, x, y, 'width:', width
	temp = False
	if x == 0 and y > 0:
		struct = structure(width + 1) - 1 - y
		temp = True
	else:
		struct = structure(width)

	if struct + y >= n:
		return 0.0
	elif temp:
		return 1.0

	extra = n - struct
	layer = structure(width + 1) - struct
	side = long(layer / 2)

	#print 'layer', layer, 'side', side
	#print extra

	if extra >= side + y + 1:
		return 1.0

	# Need at least y times on one side
	# P(times on one side >= y)
	prob = 0.0
	for i in range(y + 1, extra + 1):
		prob += choose(extra, i) * (0.5 ** i) * (0.5 ** (extra - i))

	return prob

def main():
	f = open(sys.argv[1], 'r')
	count = int(f.readline())
	for i in range(count):
		n, x, y = [long(x) for x in f.readline().split()]
		print 'Case #' + str(i + 1) + ': ' + str(prob(n, x, y))

if __name__ == "__main__":
	main()