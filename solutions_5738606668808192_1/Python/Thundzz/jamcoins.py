import sys
from math import sqrt
from math import floor


def tryFindSmallestDivisor(n, limit):
	if n % 2 == 0:
		return 2
 	limit = min(int(sqrt(n)), limit)
 	# If you can't find a divisor smaller than a limit, you can just stop there.
	for i in xrange(3, limit,2):
		if n % i == 0:
			return i
	return -1

def interpret_candidate(candidate, base):
	return reduce(lambda x,y:base*x + y, [int(c) for c in candidate])

def count_ones(string):
	return reduce(lambda x,y: x+y, [1 for c in string if c == '1'])

def bounds(length, base):
	mini = ['0'] * length
	mini[0] = '1'
	mini[length-1] = '1'
	maxi = ['1'] * length
	return interpret_candidate(mini, base), interpret_candidate(maxi, base)

def is_jamcoin(candidate):
	divisors = {}
	for base in range(2,11):
		decimalcandidate = interpret_candidate(candidate, base)
		divisor = tryFindSmallestDivisor(decimalcandidate, 1000)
		divisors[base] = divisor
		if divisor == -1: 
			return False, divisors
	return True, divisors;


def next_candidate(candidate):
	length = len(candidate)
	base_candidate = ['0'] * length
	base_candidate[0] = '1'
	base_candidate[length-1] = '1'
	inner = (int(candidate[1:-1],2)+1) << 1
	outer =  int(''.join(base_candidate),2)
	return bin(inner | outer)[2:]


def find_jamcoins(length, number):
	mini, maxi =  bounds(length, 2)
	first_candidate = bin(mini)[2:]
	last_candidate = bin(maxi)[2:]
	candidate = first_candidate
	found_jamcoins = 0
	while found_jamcoins < number and candidate != last_candidate:
		candidate = next_candidate(candidate)
		is_valid, divisors = is_jamcoin(candidate)
		if(is_valid):
			yield candidate, divisors
			found_jamcoins +=1

def main():
	t = int(sys.stdin.readline().strip())
	for i in range(1,t+1):
		[length, number] = sys.stdin.readline().strip().split()
		jamcoins = find_jamcoins(int(length), int(number))
		print "Case #%d:" % i
		for candidate, divisors in jamcoins:
			print candidate,
			for base in range(2,11):
				print divisors[base],
			print ""

if __name__ == '__main__':
	main()





