#!/usr/bin/env python2
import sys



# fq = []
# for i in xrange(10 ** 7 * 2):
# 	if palindrome(i) and palindrome(i ** 2):
# 		fq.append(i ** 2)
# print fq

fq = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L, 100000020000001L] 

def palindrome(n):
	rev = 0
	i = n

	while (n > 0):
		rev = rev * 10 + n % 10;
		n /= 10;

	return i == rev

def solve(A,B):
	res = 0
	for x in fq:
		if (x >= A) and (x <= B):
			res += 1

	return res

cases = int(sys.stdin.readline())


for case in range(cases):
	line = sys.stdin.readline()[:-1].split(" ")
	A = int(line[0])
	B = int(line[1])
	print "Case #%d: %d" % (case+1,solve(A,B))

		