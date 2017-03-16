# Hezekiah's Code Jam Solution
# Usage: python3 codejam.py < file.in > file.out

import math

def more(line):
	return 0

def palindromes(minimum, maximum):
	if minimum <= 1:
		if minimum == 0:
			yield 0
		yield 1
		minimum = 2
	for length in range(math.ceil(math.log10(minimum)), math.ceil(math.log10(maximum)) + 1):
		half = length // 2
		if half == 0:
			for palindrome in range(2, 10):
				if palindrome >= minimum and palindrome <= maximum:
					yield palindrome
		else:
			for number in range(10 ** (half - 1), 10 ** half):
				string = str(number)
				if half * 2 == length:
					palindrome = int(string + string[::-1])
					if palindrome >= minimum and palindrome <= maximum:
						yield palindrome
				else:
					for digit in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
						palindrome = int(string + digit + string[::-1])
						if palindrome >= minimum and palindrome <= maximum:
							yield palindrome

def solve(lines):
	ab = lines[0].split()
	count = 0
	for palindrome in palindromes(math.ceil(math.sqrt(int(ab[0]))), math.floor(math.sqrt(int(ab[1])))):
		string = str(palindrome * palindrome)
		if string == string[::-1]:
			count += 1
	return str(count)

def main():
	cases = int(input())
	for case in range(1, cases + 1):
		lines = [input()]
		for line in range(0, more(lines[0])):
			lines.append(input())
		print("Case #" + str(case) + ": " + solve(lines))

main()
