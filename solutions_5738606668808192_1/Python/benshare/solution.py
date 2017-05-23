import math

p = open("Primes")
curr_line = p.readline()
list_of_primes = map(int,curr_line.split(", "))

def isPrime(num):
	limit = int(math.sqrt(num))+1
	curr = 0
	val = list_of_primes[curr]
	while val < limit and val < 1000000:
		if num%val == 0:
			return val
		curr += 1
		val = list_of_primes[curr]
	return 1

def toBinary(num,digits):
	if num == 0:
		result = ""
		for i in range(0,digits):
			result += '0'
		return result
	result = toBinary(num/2,digits-1)
	if num%2 ==0:
		result += '0'
	else:
		result += '1'
	return result

def fromBase(string,base):
	if (string == ""):
		return 0
	total = base*fromBase(string[:len(string)-1],base)
	total += int(string[len(string)-1])
	return total

def isJamcoin(string):
	vals = []
	for i in range(2,11):
		vals.append(fromBase(string,i))
	divisors = [True]
	for v in vals:
		n = isPrime(v)
		if n == 1:
			return [False,v,n]
		divisors.append(n)
	return divisors


f = open('C-large.in')
output = open('C-large.out','w')
curr_line = f.readline()
numCases = int(curr_line)
for i in range(0,numCases):
	curr_line = f.readline()
	output.write("Case #%d:" %(i+1))
	strs = curr_line.split(' ')
	N = int(strs[0])
	J = int(strs[1])
	numFound = 0
	n = 0
	inDigs = N-2
	while numFound < J and n < 2**(inDigs):
		currString = "1"
		currString += toBinary(n,inDigs)
		currString += "1"
		result = isJamcoin(currString)
		if result[0]:
			for i in range(1,len(result)):
				currString += " " + str(result[i])
			output.write("\n" + currString)
			numFound += 1
		n += 1


