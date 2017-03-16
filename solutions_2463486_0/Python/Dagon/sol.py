#!/usr/bin/pypy

import sys

def isPal(num):
	s = str(num)
	for i in range(len(s)):
		if s[i] != s[len(s) - 1 - i]:
			return False
	return True
#
#numbers = {9}
#for length in range(1, 50):
#	print length
#	half = (length + 1) // 2
#	for mask in range(1, 1 << half, 2):
#		for two in range(-1, half):
#			#print length, mask, two, half
#			tmp = mask
#			number = []
#			for _ in range(half):
#				number.append(tmp % 2)
#				tmp //= 2
#			#print number
#			if two >= 0:
#				number[two] = 2
#			if length % 2 == 0:
#				number.extend(reversed(number))
#			else:
#				number.extend(reversed(number[:-1]))
#			#print number
#			num = 0
#			d = 1
#			for digit in number:
#				num += d * digit
#				d *= 10
#			if (isPal(num * num)) == True and (numbers.isdisjoint({num * num})):
#				numbers.add(num * num)
#
#print numbers

numbers = [9]

def generate(length, current, wasTwo, numbers):
	if len(current):
		if current[0] != '0':
			tmp = int(current)**2
			if isPal(tmp):
				numbers.append(tmp)
			else:
				return
	if len(current) >= length:
		return
	generate(length, "0" + current + "0", wasTwo, numbers)
	generate(length, "1" + current + "1", wasTwo, numbers)
	if not wasTwo:
		generate(length, "2" + current + "2", True, numbers)

length = 55

generate(length, "", False, numbers)
generate(length, "0", False, numbers)
generate(length, "1", False, numbers)
generate(length, "2", True, numbers)

numbers.sort()

n = int(raw_input())
for testCase in (range(1, n + 1)):
	l, r = map(int, raw_input().split())
	ans = 0
	for num in numbers:
		if (l <= num) and (num <= r):
			ans += 1
		if (num > r):
			break
	print "Case #" + str(testCase) + ": " + str(ans)
