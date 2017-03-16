def to_bin(n):
	l = []
	while n != 0:
		l.append(n % 2)
		n //= 2
	l.reverse()
	res = 0
	for d in l:
		res = 10 * res + d
	return res
	
def to_dec(n, b):
	l = str(n)
	res = 0
	for d in l:
		res = b * res + int(d)
	return res
	
def divisor(n):
	for p in primes:
		if n % p == 0:
			return p
		if p * p > n:
			return -1
	return -1

N = 1<<17
T = [0] * (N + 5)
primes = []

i = 2
while i*i <= N:
	if T[i] == 1:
		i += 1
		continue
	for j in range(i * i, N + 1, i):
		T[j] = 1
	i += 1

for i in range(2, N + 1):
	if T[i] == 0:
		primes.append(i)
	
ans = []	
for i in range((1<<31) + 1, 1<<32, 2):
	n = to_bin(i)
	div = []
	for j in range(2, 11):
		x = to_dec(n, j)
		d = divisor(x)
		if d == -1:
			break
		div.append(d)
	if len(div) == 9:
		ans.append((n, div))
	if len(ans) == 500:
		break

print ("Case #1:")
for (n, l) in ans:
	print (n, end=' ')
	for x in l:
		print (x, end=' ')
	print ('')
	
	
