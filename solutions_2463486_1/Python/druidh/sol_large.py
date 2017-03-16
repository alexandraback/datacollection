import sys
import math

def read_ints():
	return map(int, sys.stdin.readline().split())
#	return [int(x) for x in sys.stdin.readline().split()]

max_num = 1
lista = []

(T,) = read_ints()
for case in range(1, T + 1):
	A, B = read_ints()
	a = int(math.ceil(math.sqrt(A)))
	b = int(math.floor(math.sqrt(B)))
	if (b > max_num):
		for i in xrange(max_num, b+1):
			i_t = str(i)
			if (i_t == i_t[::-1]):
				i2 = i**2
				i2_t = str(i2)
				if ((i2_t == i2_t[::-1]) and (i2 not in lista)):
					lista.append(i2)
		max_num = b
	
	ans = 0
	for l in lista:
		if (l >= A) and (l <= B):
			ans += 1

	print "Case #%d: %d" % (case, ans)
	
