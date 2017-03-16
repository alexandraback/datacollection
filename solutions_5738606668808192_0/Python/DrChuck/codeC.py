# codejam C
from math import sqrt
primes = {}
def findFactor(num):
	if num in primes: return False
	for n in range(2, 100):
		if num % n == 0:
			primes[num] = str(n)
			return str(n)
	primes[num] = False
	return False
count = 0
print "Case #1:" 
t = raw_input()
line = raw_input()
n, j = int(line.split()[0]), int(line.split()[1])
num = int("1" + "0" * (n-2) + "1",2)
while count < j:
	num += 2
	found = False
	factors = []
	for i in range(2,11):
		test = int(bin(num)[2:],i)
		rst = findFactor(test)
		if rst == False:
			break
		else:
			factors.append(rst)
		if i == 10:
			found = True
			print bin(num)[2:], " ".join(factors)
	if found: 
		count += 1
#print primes