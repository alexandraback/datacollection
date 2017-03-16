#!/usr/bin/env python
import sys
import primes
import random

# Most numbers have small factors. 
# Hypothesis: there are lots of jamcoins.
# Approach: pick random numbers that satisfy the criteria, and check if they are jamcoins

# Input: l -list of binary digits, b - number greater than or equal to 2
# Output: the number in base b
def in_base(l, b):
	out = 0
	for i in range(len(l)):
		out += l[i] * b ** (len(l) - 1- i)
	return out

# Input: number n
# Output: a factor of n, or -1 if n is not divisible by the first 1000 primes
def small_factor(n):
	for i in primes.primes:
		if n % i == 0:
			return i
	return -1


# Input: list of binary digits l
# Output: If l represents a jamcoin, then the list of witnessing factors.
#         If l cannot be verified to be a jamcoin using the first 1000 primes,
#         then -1.
def check_jamcoin(l):
	jamcoin = True
	factors = []

	# Check bases 2 through 10
	for base in range(2, 11):
		n = in_base(l, base)
		fact = small_factor(n)
		if fact == -1:
			jamcoin = False
			break
		factors += [fact]

	if jamcoin:
		return factors
	return -1

# Input: l1, l2 - two lists of digits with the same length
# Output: True if and only if the sequences are different
def different(l1, l2):
	for i in range(len(l1)):
		if l1[i] != l2[i]:
			return True
	return False
		

# Input: n_digits is a number
# Output: a random jamcoin with n_digits + 2 digits 
def get_jamcoin(n_digits):
	while True:
		# Pick a random jamcoin candidate
		candidate = [1]
		for i in range(n_digits):
			candidate += [random.randint(0, 1)]
		candidate += [1]

		# Check all bases
		factors = check_jamcoin(candidate)

		if(factors == -1):
			continue

		return (candidate, factors)

# Input: n_digits, n - numbers
# Output: n jamcoins, each having n_digits+2 digits
def get_n_jamcoins(n_digits, n):
	jamcoins = []

	while(len(jamcoins) < n):
		jamcoin = get_jamcoin(n_digits)

		# Check that it's not already in there (very remote chance that it is!)
		for i in jamcoins:
			if not different(i[0], jamcoin[0]):
				continue

		jamcoins += [jamcoin]

	return jamcoins

# Input: the output of get_n_jamcoins
# Output: a string representation of the jamcoins and their factors
def jamcoins_to_str(jamcoins):
	out = ""
	for (digits, factors) in jamcoins:
		for i in digits:
			out += str(i)
		for i in factors:
			out += " " + str(i)
		out += "\n"
	return out


# Get input/output files and open them
if(len(sys.argv) != 3):
	print "Usage ./jamcoin.py <input> <output>"
	sys.exit(1)

f = open(str(sys.argv[1])) 
out = open(str(sys.argv[2]), "w")

# Remove the first line of the input (which contains the length)
lines = [l for l in f]
lines = lines[1:]

# For each input line, find the potter number
count = 0
for i in lines:
	count += 1
	values = i.split()
	p = get_n_jamcoins(int(values[0])-2, int(values[1]))
	out.write("Case #" + str(count) + ":\n" + jamcoins_to_str(p))
