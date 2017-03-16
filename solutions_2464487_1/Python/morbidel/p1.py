import math
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
        
with open('A-large.in') as f:
	nt = int(f.readline())
	for t in range(1, nt + 1):
		print 'Case #' + str(t) + ':',
		r, t = [int(x) for x in f.readline().split()]
		delta = (2 * r - 1) * (2 * r - 1) + 8 * t
		x = ((1 - 2 * r) + isqrt(delta)) / 4
		print int(x)