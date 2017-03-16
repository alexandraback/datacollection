#!/usr/bin/python
import math
import sys

def is_palindrome(n):
	n = str(n)
	ok = True
	for z in range(0, len(n)/2):
		ok = ok and n[z] == n[len(n)-z-1]
	return ok

def get_generators():
	# list of the numbers that 'could' be generators (don't have a proof)
	generators = []
	for i in range(0, 25):
		for j in range(i+1, 25):
			for k in range(j+1, 25):
				for l in range(k+1, 25):
					base = bin((2**i)+(2**j)+(2**k)+(2**l))
					base = str(base)[2:]
					generators.append(base + base[::-1])
					generators.append(base + '0' + base[::-1])
					generators.append(base + '1' + base[::-1])
					generators.append(base + '2' + base[::-1])

	for i in range(0, 25):
		for j in range(i+1, 25):
			for k in range(j+1, 25):
				base = bin((2**i)+(2**j)+(2**k))
				base = str(base)[2:]
				generators.append(base + base[::-1])
				generators.append(base + '0' + base[::-1])
				generators.append(base + '1' + base[::-1])
				generators.append(base + '2' + base[::-1])

	for i in range(0, 25):
		for j in range(i+1, 25):
			base = bin((2**i)+(2**j))
			base = str(base)[2:]
			generators.append(base + base[::-1])
			generators.append(base + '0' + base[::-1])
			generators.append(base + '1' + base[::-1])
			generators.append(base + '2' + base[::-1])

	for i in range(0, 25):
		base = bin((2**i))
		base = str(base)[2:]
		generators.append(base + base[::-1])
		generators.append(base + '0' + base[::-1])
		generators.append(base + '1' + base[::-1])
		generators.append(base + '2' + base[::-1])

	for i in range(0, 26):
		base = str((10**i) * 2)
		generators.append(base + base[::-1])
		generators.append(base + '0' + base[::-1])
		generators.append(base + '1' + base[::-1])
		generators.append(base + '2' + base[::-1])

	for i in range(1,10):
		generators.append(i)
	return generators


fair_and_squares = []

for gen in get_generators():
	if is_palindrome(int(gen) ** 2):
		fair_and_squares.append(int(gen) ** 2)

test_cases = 0
numbers = []
for lines in sys.stdin.readlines():
	for number in lines.split(' '):
		numbers.append(int(number))

test_cases = numbers[0]
numbers = numbers[1:]
for i in range(1, test_cases+1):
	A = numbers[0]
	B = numbers[1]
	cnt = 0
	for fas in fair_and_squares:
		if fas <= B and fas >= A:
			cnt = cnt + 1
	print "Case #%d: %d" % (i, cnt)
	numbers = numbers[2:]

#	i = i + 1
#i = 1
#while i <= 25:
#	gen = int(lambda x: x + x[::-1])(str((10 ** i) * 2))
#	pal = str(gen ** 2)
#	isfas = True
#	for z in range(0, len(pal)/2):
#		isfas = isfas and (pal[z] == pal[len(pal)-1-z])
#		if not isfas:
#			break
#	if isfas:
#		print pal

#	i = i + 1

#while i < 8:
#	for j in range(10**i, 10**(i+1)):
#		gen = j
#		pal = int(str(j) + str(j)[::-1])
#		pal = pal ** 2
#		if pal > B:

#			ok = False
#			break
#		if pal < A:
#			continue
#		pal = str(pal)
#		isfas = True
#		for z in range(0, len(pal)/2):
#			isfas = isfas and (pal[z] == pal[len(pal)-1-z])
#			if not isfas:

#				break
#		if isfas:
#			print gen
#			count = count + 1
#	if not ok:
#		break
#	i = i + 1

#i = 1
#while i < 10**8:
#	p = i
#	i = i + 1
#	if not is_palindrome(p):
#		continue
#	gen = p
#	pal = p ** 2
#	if not is_palindrome(pal):
#		continue
#	print gen
#	i = i + 1
#print count

