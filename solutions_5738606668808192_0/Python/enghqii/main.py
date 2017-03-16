import math

T = 1
N = 16
J = 50

def is_prime(n) :
	sqrn = math.sqrt(n)

	for i in range(2, int(sqrn)) :
		if n % i == 0 :
			return i
	return False

def to_base(jamcoin, base) :
	#local_jamcoin = list(jamcoin)
	#local_jamcoin.reverse()

	ret = 0
	i = 0

	for b in reversed(jamcoin) :
		if b == 1:
			ret += base ** i;
		i += 1
	return ret

def print_jamcoin(jamcoin, divisors) :

	for digit in jamcoin :
		print(str(digit), end = "")

	for divisor in divisors :
		print(" " + str(divisor), end = "")
	print()

# main begin

print("Case #" + str(T) + ":")

jamcoinCount = 0

for i in range(0, 2 ** (N-2)) :

	# print("==========================")

	# jamcoin create BEGIN
	jamcoin = []

	for j in range(0, N-2) :
		if (i >> j) & 1 != 0 :
			jamcoin.append(1)
		else:
			jamcoin.append(0)

	jamcoin.insert(0, 1)
	jamcoin.append(1)
	# jamcoin create END

	# check if the jamcoin is valid BEGIN
	divisors = []
	notJamcoin = False;
	
	for i in range(2, 11) :
		based = to_base(jamcoin, i)
		divisor = is_prime(based)

		#print("(" + str(based) + ", " + str(divisor) + ")")

		if divisor != False :
			divisors.append(divisor)
		else:
			notJamcoin = True
			break
	# checking end

	if notJamcoin:
		continue

	jamcoinCount += 1
	#print(jamcoinCount)
	print_jamcoin(jamcoin, divisors)

	if jamcoinCount >= J :
		break

# main end