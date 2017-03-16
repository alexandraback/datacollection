import os, sys
from pprint import *

inFile = None
outFile = None

def isPalindrome(b):
	a = str(b)
	return a == ''.join(reversed(a))




def printAnswer(case, answer):
	outFile.write('Case #{0}: {1}\n'.format(case+1, answer))

def solveCase(caseNo):
	fairs = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 
	1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 
	125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 
	12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 
	1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 
	1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 
	100000020000001, 100220141022001, 102012040210201, 102234363432201, 
	121000242000121, 121242363242121, 123212464212321, 123456787654321, 
	400000080000004 ]
	(a,b) = map(int, inFile.readline().strip().split())

	ans = 0
	for fair in fairs:
		if fair >= a and fair <= b:
			ans += 1
	printAnswer(caseNo, ans)

def main():
	cases = int(inFile.readline().strip())
	for case in range(cases):
		solveCase(case)



if __name__ == '__main__':

	# for x in xrange(10000000):
	# 	if isPalindrome(x) and isPalindrome(x*x):
	# 		print x, x*x


	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()