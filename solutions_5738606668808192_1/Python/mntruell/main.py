import math

def input(filename):
	lines = open(filename).read().split("\n")
	numCases = int(lines.pop(0))
	linesPerCase = int(len(lines)/numCases)
	return [[lines.pop(0) for b in range(linesPerCase)] for a in range(numCases)]


def output(filename, strings):
	file = open(filename, 'w')
	for a in range(len(strings)):
		print("Case #"+str(a+1)+":\n"+strings[a])
		file.write("Case #"+str(a+1)+":\n"+strings[a])

def convertToDecimal(jamcoin, base):
	return int(str(jamcoin), base)

def is_prime(n):
	for a in range(3, int(math.sqrt(n))):
		if n % a == 0:
			return False
	return True

def isPrimeGuess(n):
	for a in range(3, int(math.sqrt(math.sqrt(math.sqrt(n))))):
		if n % a == 0:
			return False
	return True

def isJamcoin(jamcoin, n):
	chars = str(jamcoin)
	if len(chars) == n and chars[0] == '1' and chars[len(chars)-1] == '1':
		for a in range(2, 11):
			print(str(a) + " " + str(convertToDecimal(jamcoin, a)))
			if isPrimeGuess(convertToDecimal(jamcoin, a)):
				return False
	else:
		return False

	return True

def divisors(jamcoin):
	divisorsList = []
	for a in range(2, 11):
		num = convertToDecimal(jamcoin, a)
		for i in range(3, num):
			if num % i == 0:
				divisorsList.append(i)
				break
		
	return divisorsList

cases = input("input3.txt")

strings = []
for case in cases:
	n = int(case[0].split(" ")[0])
	j = int(case[0].split(" ")[1])

	jamcoins = []
	jamcoin = int("1"+"".join(["0" for a in range(n-2)])+"1")
	divs = []
	while len(jamcoins) < j and len(str(jamcoin)) == n:
		jamcoin = int(bin(convertToDecimal(jamcoin, 2)+1)[2:])
		print(len(jamcoins))
		if isJamcoin(jamcoin, n):
			jamcoins.append(jamcoin)
			divs.append(divisors(jamcoin))
	string = ""
	for a in range(len(jamcoins)):
		string += str(jamcoins[a]) + " "
		for b in range(len(divs[a])):
			string += str(divs[a][b]) + " "
		string += "\n"
	strings.append(string)

output("output3.txt", strings)