import sys
import math

n = int(next(sys.stdin))

def isqrt(x):
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

for i, line in enumerate(sys.stdin):
	a, b = line.split(" ")
	r = int(a)
	t = int(b)

	n = (1 - 2 * r + isqrt(1 - 4 *r + 4 * r**2 + 8*t))/4
	# n = 0

	# d = r

	# while True:
	# 	area = (d + 1)**2 - d** 2
	# 	t -= area
	# 	if t >= 0:
	# 		n += 1
	# 		d += 2
	# 	else:
	# 		break
	print("Case #%d: %d" % (i + 1, n))
