# Numbers are too big to use C :(
from math import sqrt

def getInBase(n, base):
	if n == 0:
		return 0
	return getInBase(int(n >> 1), base) * base + (n & 1)	

def getDivisor(num):
	s   = 5000 # Whatever, we don't want all of them
	i   = 3

	if((num % 2) == 0):
		return 2

	while i <= s:
		if((num % i) == 0):
			return i
		i += 2
	return None

def isCoin(n):
	divisors = [0] * 9
	for base in range(2, 11):
		num = getInBase(n, base)
		div = getDivisor(num)
		if div is None:
			return False
		divisors[base - 2] = div
	print(bin(n)[2:] + " " + " ".join([str(k) for k in divisors]))
	return True
	
def solve(N, J):
	current = (1 << (N - 1)) | 1
	count   = 0
	while count < J:
		if isCoin(current):
			count += 1
		current += 2

print("Case #1:")
# solve(16, 50)
solve(32, 500)