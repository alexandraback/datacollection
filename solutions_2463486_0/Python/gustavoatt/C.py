#!/usr/bin/env python
import sys
import math

def palindromes_up_to(limit):
	result = [x for x in xrange(1, 10)]

	i, cont = 1, True
	while cont:
		rev = str(i)[::-1]
		cont = False
		for d in "0123456789":
			n = int(str(i) + d + rev)
			if n <= limit:
				result.append(n)
				cont = True

		i += 1

	return result

def is_fair(n):
	EPS = 0.0000001

	nsqrt = math.sqrt(n)
	if (nsqrt - math.trunc(nsqrt)) > EPS:
		return False

	s = str(math.trunc(nsqrt))
	for i in xrange(len(s)):
		if s[i] != s[len(s) - i - 1]:
			return False
	return True

def smaller_eq(palin, x):
	count = 0
	for p in palin:
		if p <= x:
			count += 1
	return count

def smaller(palin, x):
	count = 0
	for p in palin:
		if p < x:
			count += 1

	return count

if __name__ == '__main__':
    palin = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 
    1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 
    125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 
    12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 
    1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 
    1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]

    T  = int(sys.stdin.readline().strip())
    for CASE in xrange(1, T + 1):
        A, B = map(int, sys.stdin.readline().strip().split())

        print "Case #{}: {}".format(CASE, smaller_eq(palin, B) - smaller(palin, A))
