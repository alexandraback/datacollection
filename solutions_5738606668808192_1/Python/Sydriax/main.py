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

def is_compound(n):
	max = min(int(math.sqrt(n))+1, 200000)
	for i in range(3, max):
		if n % i == 0:
			return i
	return 0

def isJamcoin(jamcoin):
	chars = str(jamcoin)
	divisors = []
	for a in range(2, 11):
		#print(str(a) + " " + str(convertToDecimal(jamcoin, a)))
		factor = is_compound(convertToDecimal(jamcoin, a))
		if factor == 0:
			return []
		else:
			divisors.append(factor)
	return divisors

def getCoinFromNum(num):
	compare = 1;
	while compare * 2 < num:
		compare *= 2
	answer = ""
	while(compare >= 1):
		if compare <= num:
			answer += '1'
			num -= compare
		else:
			answer += '0'
		compare /= 2
	return answer

cases = input("input3.txt")

strings = []
for case in cases:
	n = int(case[0].split(" ")[0])
	j = int(case[0].split(" ")[1])

	counter = 0
	jamcoins = []
	num = 2**(n-1) + 1
	divs = []
	while len(jamcoins) < j:
		jamcoin = getCoinFromNum(num)
		divisors = isJamcoin(jamcoin)
		if len(divisors) != 0:
			jamcoins.append(jamcoin)
			divs.append(divisors)
			print(len(jamcoins))
		counter += 1
		num += 2
	print("Counter: " + str(counter))
	string = ""
	for a in range(len(jamcoins)):
		string += str(jamcoins[a]) + " "
		for b in range(len(divs[a])):
			string += str(divs[a][b]) + " "
		string += "\n"
	strings.append(string)

output("output3.txt", strings)