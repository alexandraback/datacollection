#!/usr/bin/env python
import sys, math

DIGITS = 14

def num_digits(n):
	return int(math.log10(n)) + 1

def is_palindrome(n):
	s = str(n)
	for l in xrange(len(s)):
		r = len(s) - (1 + l)
		if s[l] != s[r]:
			return False
	return True

def main(argv=None):
	if argv is None:
		argv = sys.argv
	
	# Pre-build the list of fair square numbers - works for up to 10^14.
	# Special cases.
	fair_squares = [1, 4, 9, 121, 484]

	# Further fair squares can be found as follows. For 11 and 22, add 0, 1 or 2
	# (also 00, 11, 22) as middle digits, squaring to check that the result is a
	# palidrome. Repeat for all such square roots of fair squares with an even
	# number of digits, that is, continue with 1001, 1111, 1221, 2002, ...
	prevList = [1, 2]
	for d in xrange(1, int(DIGITS / 2) + 2):
		newList = []
		for n in prevList:
			strn = str(n)

			# Odd number of digits.
			for a in ('0', '1', '2'):
				s = strn + a
				m = int(s + strn[::-1]) # Append the reversed original head.
				mSq = m * m
				if is_palindrome(mSq):
					fair_squares.append(mSq)

				# Even number of digits.
				l = int(s + s[::-1]) # This time reverse the head with extra digit.
				lSq = l * l
				if is_palindrome(lSq):
					fair_squares.append(lSq)
					newList.append(s)
		prevList = newList

	# There aren't that many for small numbers...
	fair_squares = sorted(fair_squares)

	T = int(sys.stdin.readline())
	for t in xrange(T):
		A, B = map(long, sys.stdin.readline().split(" "))
		count = 0

		i = 0
		while fair_squares[i] <= B:
			if i < len(fair_squares) and fair_squares[i] >= A:
				count += 1
			i += 1
		
		print "Case #%d: %d" % (t + 1, count)

if __name__ == "__main__":
	sys.exit(main())

