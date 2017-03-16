import math

def isPrime(n):
	i = 2
	while True:
		if(i * i > n):
			break
		if(n % i == 0):
			return i
		i += 1
	return 0
 
N = 32
M = 500

a = [0 for i in range(N)]
b = [0, 0, 3, 2, 5, 2, 7, 2, 3, 2, 11]
a[0] = 1
a[N-1] = 1

print "Case #1:" 

i = 0
while True:
	for j in range(1, N-1):
		a[j] = (i >> (N-2 - j)) % 2;

	find = True

	for j in range(2, 11):
		n = 0
		for k in a:
			n = n * j + k

		if n % b[j] != 0:
			find = False
			break

	i += 1

	if find:
		M -= 1
		ans = ""
		for j in a:
			ans += str(j)
		print ans,
		for j in range(2, 11):
			print b[j],
		print ''
		if M == 0:
			break


