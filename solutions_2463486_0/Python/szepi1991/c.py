#!/usr/bin/python3
from bisect import *
import math

LIM = 1111


def find_ge_ind(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return i
    raise ValueError

def find_le_ind(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return i-1
    raise ValueError

def isPalindrome(num):
	'Returns true iff the supplied integer is a palindrome'
	strNum = str(num)
	good = True
	for c in range(int(len(strNum)/2)):
		if strNum[-c-1] != strNum[c]:
			good = False
			break
	return good

def testIsPal(num):
	print(str(num) + ": " + str(isPalindrome(num)))

def findAll():
	final = []
	cur = 1;
	while (True):
		pal = str(cur)
		pal1 = int(pal + pal[-2::-1])   # shorter
		pal2 = int(pal + pal[::-1])
#		print(pal + " -> " + str(pal1) + ", " + str(pal2))

		pot1 = pal1*pal1
		if pot1 > LIM:
			break;
		else:
			if isPalindrome(pot1):
				final.append(pot1)
		
		pot2 = pal2*pal2
#		print(str(pot1) + ", " + str(pot2))
		if pot2 <= LIM and isPalindrome(pot2):
			final.append(pot2)
		
		cur += 1
	
	final.sort()
	return final


#testIsPal(1)
#testIsPal(11)
#testIsPal(121)
#testIsPal(91619)
#testIsPal(12)
#testIsPal(1231)
#testIsPal(123)


goodNums = findAll()
#print(str(goodNums))

cases = int(input())
for case in range(1, cases+1):
	line = input()
#	print(str(line) + "\n")
	words = line.split()
	A = int(words[0])
	B = int(words[1])
	nums = 0
	try:
		startInd = find_ge_ind(goodNums, A)
		endInd = find_le_ind(goodNums, B)
		nums = endInd - startInd + 1
	except:
		# if there is an exception nums should stay 0
		pass
	print("Case #" + str(case) + ": " + str(nums))


