isp = [True for i in range(3000000)]
primes = [2]

isp[0] = False
isp[1] = False

for i in range(4,3000000,2):
	isp[i] = False

for i in range(3,3000000,2):
	if isp[i] :
		primes.append(i)
		for j in range(i*i,3000000,i):
			isp[j] = False

print '\nPRIME_SIEVE_IS_DONE\n'

def ISP(n):
	if n < 3000000 :
		return isp[n]
	for x in primes :
		if x*x > n :
			return True
		if n % x == 0 :
			return False
	return True

def fac(n):
	for x in primes :
		if n%x == 0 :
			return x
	return -1

def base(n,b):
	ans = 0
	n = n[::-1]
	for i in range(len(n)):
		if n[i] == '1' :
			ans += (b**i)
	return ans

OUT = []

i = -1
while len(OUT) < 50 :
	i += 1

	L = len(bin(i)) - 2
	if L == 14 :
		s = '1' + bin(i)[2:] + '1'
	else:
		s = '1' + '0'*(14-L) + bin(i)[2:] + '1'

	flag = 1
	for b in range(2,11):
		if ISP( base(s,b) ) :
			flag = 0
			break
			
	if flag :
		tmp = [s]
		for b in range(2,11):
			tmp.append( fac(base(s,b)) )
		OUT.append(tmp)

OUT.sort()
for x in OUT:
	for y in x :
		print y,
	print '\n'