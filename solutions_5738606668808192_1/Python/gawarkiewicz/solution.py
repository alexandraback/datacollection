primes = []

def fromBase(num, base):
	ret = 0
	for i in range(31, -1, -1):
		ret = ret * base + (1 if (num & (1 << i)) else 0)
	return ret

def divider(num):
	for p in primes:
		if p >= num:
			break;
		if (num % p == 0):
			return p;
	return 1;

def check(num):
	out = []
	for i in range(2, 11):
		out.append(divider(fromBase(num, i)))
		if out[-1] == 1:
			return out;
	return out;


cnt = 1000000
isPrime = [1] * cnt
for i in range(2, cnt):
	if isPrime[i]:
		primes.append(i)
		for j in range(i*i, cnt, i):
			isPrime[j] = 0
N=32
J=500
print("Case #1:");

i=0
while i < (1 << (N-2)) and J > 0:
	num = (1 << (N-1)) | (i << 1) | 1;
	num10 = fromBase(num, 10);
	out = check(num)
	if min(out) > 1:
		print(('%d ' % num10) + ' '.join(['%d' % d for d in out]))
		J -= 1
	else:
		#print("\t" + ('%d ' % num10))
		pass
	i += 1