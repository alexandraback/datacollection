import sys
primeTable = list()

def buildPrimeTable():
	table = [True for i in range(2 ** 17)]
	for i in range(2, 2 ** 16):
		if not table[i]:
			continue
		primeTable.append(i)
		j = 1
		while i * j < 2**16:
			table[i * j] = False
			j += 1

def toBase10(string, base):
	val = 0
	for i in range(len(string)):
		val = val * base + int(string[i])
	return val

def next(string):
	for i in range(len(string)-1, -1, -1):
		if string[i] == "1":
			continue
		else:
			return string[0:i] + "1" + "0" * (len(string)-i-2) + "1"

def solve():
	T = int(input())
	outputFile = open('C-small.out', 'w')
	N, J = map(int, input().split())
	s = "1" + "0" * (N - 2) + "1"
	print("Case #1:", file=outputFile)
	while J > 0:
		l = []
		for i in range(2, 11):
			num = toBase10(s, i)
			for j in primeTable:
				if j ** 2 > num:
					break
				if num % j == 0:
					l.append(j)
					break
		if len(l) == 9:
			print(s, end="", file=outputFile)
			for e in l:
				print(" %d" % e, end = "", file=outputFile)
			print(file=outputFile)
			J -=1
		s = next(s)
buildPrimeTable()
solve()



