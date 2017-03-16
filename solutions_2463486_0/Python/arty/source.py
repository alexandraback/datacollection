import math
import sys

def is_perfect_square(x):
	n = round(math.sqrt(x))
	return n * n == x
	
def generate_palindromes(n):
	if len(str(n)) == 1:
		return n, int(str(n) + str(n))
	else:
		return int(str(n) + str(n)[-2::-1]), int(str(n) + str(n)[::-1])
		
def is_palindrome(n):
	x = str(n)
	for i in range(0, len(x)/2):
		if x[i] != x[len(x)-i-1]: return False
	return True
	
def range_count(array, start, end):
	i = 0
	while (i < len(array) and array[i] < start):
		i += 1
	count = 0
	while (i < len(array) and array[i] <= end):
		i += 1
		count += 1
	return count

palindromes = []
for x in range(1,10000):
	a,b = generate_palindromes(x)
	tmp = a * a
	if (is_perfect_square(tmp) and is_palindrome(tmp)):
		palindromes += [tmp]
	tmp = b * b
	if (is_perfect_square(tmp) and is_palindrome(tmp)):
		palindromes += [tmp]
		
palindromes.sort()

T = int(sys.stdin.readline())
for t in range(1, T+1):
	a,b = sys.stdin.readline().split(" ")
	a = int(a)
	b = int(b)
	print "Case #" + str(t) + ": " + str(range_count(palindromes, a, b))