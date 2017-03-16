import math
import random

def readint():
	return int(input())

def readints():
	return [int(i) for i in input().split()]

primes = list(map(int, open("p.txt").read().strip().split()))

def random_bin(n):
	b = random.randint(0, 2**(n-2)-1)
	return bin(2**(n-1) + 2 * b + 1)[2:]

def iscomposite(n):
	limit = math.ceil(math.sqrt(n))
	for p in primes:
		if p > limit:
			break
		if n % p == 0:
			return True, p
	return False, None

def find_jamcoins(N, J):
	found = set()
	result = []
	
	while len(result) < J:
		n = random_bin(N)
		if n in found:
			continue

		factors = []
		for base in range(2, 11):
			x = int(n, base=base)
			composite, factor = iscomposite(x)
			if not composite:
				break
			factors.append(factor)
		
		if len(factors) < 9:
			continue

		found.add(n)
		result.append((n, factors))
		
	return result

def main():
	T = readint()
	
	for t in range(1, T + 1):
		N, J = readints()
		
		print("Case #%d:" % t)
		for n, factors in find_jamcoins(N, J):
			print(n, ' '.join(str(factor) for factor in factors))

main()