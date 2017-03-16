#!/usr/bin/python
import sys
import math
def div(num):
	s =  int(math.floor(math.sqrt(num)))
	for i in range(s+1)[2:]:
#		print i, num%i
		if num % i == 0:
			return i
	return 1

def non_trivial_div(s):
	ret = list()
	for base in range(11)[2:11]:
		num = int(s, base)
		d = div(num)
#		print base, num, d
		if d > 1:
			ret.append(d)
		else:
			return []
	return ret

t = raw_input()
line = raw_input()
N, J = line.split()
N, J = int(N), int(J)

start = 2**(N-1) + 1
end = 2**N -1

n = start
ans = 0
print "Case #1:"
while True:
	if n > end:
		break
	s = bin(n)[2:]
	n += 2

	ret = non_trivial_div(s)

	#sys.exit(0)
	if len(ret) != 9:
		continue
	ans += 1
	print s,
	for i in ret:
		print i,
	print
	sys.stdout.flush()
	if ans == J:
		break

