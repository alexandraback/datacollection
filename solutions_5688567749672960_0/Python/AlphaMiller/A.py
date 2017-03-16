from __future__ import print_function
import sys
import itertools

def flip(n):
	return int(str(n)[::-1])

def solve():
	# parse input
	N = int(raw_input())
	digits = len(str(N))

	print("N:", N, digits, file=sys.stderr)
	
	if N <= 19:
		return N

	addone = False
	if int(str(N)[digits/2:])==0:
		print('addone', file=sys.stderr)
		N -= 1
		digits = len(str(N))
		addone = True

	count = 0
	# solve

	# get to 10...00
	for i in range(1, digits):
		if i==1:
			count += 10
			continue
		count += int('9'*((i+1)/2))
		count += 1
		count += int('9'*(i/2))
		print(i, count, file=sys.stderr)

	count += int(str(N)[:digits/2][::-1])
	count += 1
	count += int(str(N)[digits/2:])-1
	if addone:
		count += 1

	return count

T = int(raw_input())
for case in xrange(T):
	print(case, file=sys.stderr)
	print("Case #%d: %s"%(case+1, solve()))
