import sys
tc = map(int,sys.stdin.readline().split())
j,n = map(int,sys.stdin.readline().split())

primes = [2]

def genPrimes():
	for i in range (2,2**j):
		for k in primes:
			if (k*k>i):
				primes.append(i)
				break;
			elif (i%k==0):
				break;

genPrimes();

def checkPrime(num_to_check):
	for i in primes:
		if (num_to_check%i==0):
			return i
		elif (i*i>num_to_check):
			return -1

print "Case #1: "

for i in range (0,2**(j-2)): # 2**(j-2)
	# test coin 1 + i + 1
	coin = "1" + str(bin(i))[2:].zfill(j-2) + "1"
	# print "Testing coin " + coin
	success = 1
	checksum = []
	for i in range(2,11):
		check = int(coin,i)
		check = checkPrime(check)
		if(check==-1 or check == None):
			success = 0
		checksum.append(str(check))
	if (success==1):
		print coin + " " + " ".join(checksum)
		n = n-1
	if(n==0):
		break;