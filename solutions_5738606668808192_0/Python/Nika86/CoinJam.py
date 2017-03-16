#! /usr/bin/python

def toBinaryString(N):
	if (N < 2):
		return str(N)
	else:
		return toBinaryString(N/2) + str(N % 2)

firstFewPrimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
bases = range(2, 11)


T = int(raw_input())

for t in range(1, T+1):
	print 'Case #' + str(t) + ':'

	N, J = [int(inp) for inp in raw_input().split()]

	jamCoin = (2 ** (N - 1) + 1)
	while J > 0:
		jamString = toBinaryString(jamCoin)
		
		divisors = []
		for b in bases:
			for p in firstFewPrimes:
				if int(jamString, b) % p == 0:
					divisors += [p]
					break

		if len(divisors) == len(bases):
			print jamString,
			for d in divisors:
				print d,
			print
			J -= 1

		jamCoin += 2






	