cases = int(raw_input())

from time import time


def isPrime(n):
	if n%2==0:	return 2

	startTime = time()
	i = 3
	while i < int(n**0.5)+1:

		if n%i==0:
			return i  

		# timeout for lame coins
		if time() - startTime > 3:
			return -1

		i += 2

	return -1



def isJamCoin(binaryCoin):
	deviders = []

	for i in range(2,11):

		#debugzor("@ devider " + str(i) + " for " + binaryCoin)
		
		tmp = isPrime(int(binaryCoin,i))
		if tmp == -1:
			return False
		else:
			deviders.append(tmp)

	return deviders


from random import randint

def getRandInnerCoin(n):
	return [str(randint(0,1)) for i in range(n-2)]


def debugzor(s):
	debug = False
	if debug:
		print s

for case in range(cases):
	print "Case #" + str(case+1) + ":"


	N,J = [int(i) for i in raw_input().split()]

	coinTrace = []

	# produce J jamcoins of length N
	jamcoinsLeft = J
	while jamcoinsLeft > 0:

		#debugzor("Generating randcoin")

		gen = ''.join(getRandInnerCoin(N))
		coin = '1' + gen + '1'

		if coin in coinTrace:
			continue

		tmp = isJamCoin(coin)
		if tmp != False:
			coinTrace.append(coin)
			jamcoinsLeft -= 1
			print coin + ' ' + ' '.join([str(i) for i in tmp])
