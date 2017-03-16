cases = int(raw_input())


def isPrime(n):
	#if n==2 or n==3: return True not possible for jamcoins
	if n%2==0:	return 2
	#if n<2: return 2 not possible for jamcoins
	for i in range(3,int(n**0.5)+1,2):   # only odd numbers
		if n%i==0:
			return i    

	return -1



def isJamCoin(binaryCoin):
	deviders = []

	for i in range(2,11):
		tmp = isPrime(int(binaryCoin,i))
		if tmp == -1:
			return False
		else:
			deviders.append(tmp)

	return deviders


from itertools import product


for case in range(cases):
	print "Case #" + str(case+1)


	N,J = [int(i) for i in raw_input().split()]

	innerCoinIterator = product('01',repeat=(N-2))

	# produce J jamcoins of length N
	jamcoinsLeft = J
	while jamcoinsLeft > 0:
		coin = '1' + ''.join(innerCoinIterator.next()) + '1'

		tmp = isJamCoin(coin)
		if tmp != False:
			jamcoinsLeft -= 1
			print coin + ' ' + ' '.join([str(i) for i in tmp])


'''
tmp = isJamCoin("111001")
if tmp == False:
	print "No jamcoin"
else:
	print tmp
'''