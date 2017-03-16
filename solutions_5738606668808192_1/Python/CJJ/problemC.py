#Coin Jam
import sys

def sieve (n):
	"Optimized Sieve of Eratosthenes"
	primes = [2]
	i = 3
	primcheck = [True]*((n+1)>>1)
	while i < n:
		if primcheck[i>>1]:
			primes.append(i)
			j = i
			while i*j < n:
				if primcheck[i*j>>1]:
					primcheck[i*j>>1] = False
				j += 2
		i += 2
	return primes

primes = sieve(2**16) #max N = 32

def readInput (filename):
	cases = []
	with open (filename, 'r') as file:
		numberOfCases = int(file.readline())
		for i in range(numberOfCases):
			cases.append(file.readline().replace('\n',''))
	return numberOfCases, cases
	
def writeOutput (filename, output, numberOfCases):
	with open (filename, 'w') as file:
		for i in range(numberOfCases):
			line = "Case #" + str(i+1) + ": "
			line += '\n'
			for jamcoin in output[i]:
				for value in jamcoin:
					line += str(value)
					line += ' '
				line += '\n'
			file.write(line)

def problem (inputfile=".input", outputfile="output"):
	numberOfCases, cases = readInput(inputfile)
	output = []
	for case in cases:
		N, J = [int(i) for i in case.split(' ')]
		output.append(generateJamcoin(N, J))
	writeOutput(outputfile, output, numberOfCases)
	

def generateJamcoin (N, J):
	digit = int('1' + '0'*(N-2) + '1', 2)
	found = 0
	jamcoins = []
	while found<J:
		digitString = "{0:b}".format(digit)
		divisors = getJamcoin(digitString)
		if divisors:
			found += 1
			jamcoins.append([digitString]+divisors)
		digit += 2
	return jamcoins
	

def getJamcoin (digitString):
	divisors = []
	for i in range(2,11):
		number = int(digitString, i)
		divisor = getDivisors(number)
		if divisor == 0:
			return False
		divisors.append(divisor)
	return divisors
		
def getDivisors (number):
	if number in primes:
		return 0
	for prime in primes:
		if number % prime == 0:
			return prime
	return 0
	
if __name__ == "__main__":
	problem(sys.argv[1])