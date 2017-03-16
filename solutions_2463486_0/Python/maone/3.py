import math
import sys

def palin(n):
	s = str(n)
	l = len(s)
	for k in xrange(0, l / 2):
		if s[k] != s[l - 1 - k]: return False
	return True

def sqrtpln(n):
	return palin(n) and palin(n * n)

def count(n):
	total = 0

	# 22, 202, 212, 2002, 20002, 20102 ...
	for xlen in xrange(0, 1000):
		value = int('2' + '0' * xlen + '2')
		if value <= n:
			total += 1
		else: break

		if xlen & 1:
			value = int('2' + '0' * (xlen >> 1) + '1' + '0' * (xlen >> 1) + '2')
			if value <= n:
				total += 1
			else: break
	# print '2X2: ' + str(total)
	
    # 121, 10201, 11211, 1002001, 1012101, 1102011 ...
 	for xlen in xrange(0, 1000):
 		value = int('1' + '0' * xlen + '2' + '0' * xlen + '1')
 		if value <= n: total += 1
		else: break
 
 		if xlen > 0:
 			value = int('1' + '0' * (xlen - 1) + '121' + '0' * (xlen - 1) + '1')
 			if value <= n: total += 1
			else: break
 		if xlen > 1:
 			value = int('11' + '0' * (xlen - 1) + '2' + '0' * (xlen - 1) + '11')
 			if value <= n: total += 1
			else: break
	# print '1X2X1: ' + str(total)

	s = str(n)
	l = len(s)
	hl = (l + 1) / 2
	for k in xrange(0, l - 2):
		total += (1 << k / 2)
		if k & 1:
			total += ( 1 << k / 2)
	# print '1XxX1: ' + str(total)
	
	oneorzero = True
	for k in xrange(0, hl):
		if s[k] == '0':
			continue
		elif s[k] == '1':
			if k != 0: total += (1 << (hl - k - 1))
			continue
		else:
			if k > 0:
				total += (1 << (hl - k))
			else:
				total += (1 << (hl - k - 1))
			oneorzero = False
			break
	# print '1Y1: ' + str(total)

 	if oneorzero:
 		if (l & 1):
 			value = s[0:hl] + s[0:hl-1][::-1]
 		else:
 			value = s[0:hl] + s[0:hl][::-1]
		if int(value) <= n: total += 1
	# print 'ALLZERO: ' + str(total)

	return total

def solve(n):
	if n < 1:
		return 0
	elif n < 4:
		return 1
	elif n < 9:
		return 2
	elif n < 121:
		return 3

	k = math.trunc(math.sqrt(n))
	while k * k <= n:
		k += 1
	
	return count(k - 1) + 3


T = int(sys.stdin.readline())
for t in xrange(0, T):
	A, B = [int(v) for v in sys.stdin.readline().split()] 
	print "Case #%d: %d" % (t + 1, solve(B) - solve(A - 1))

# for k in xrange(1, 10000000):
# 
# 	if palin(k) and palin(k * k):
# 		print k, k * k
# 
# 		v = solve(k * k)
# 		if t != v:
# 			print 'ERROR' + str(v) + str(t)
# 			break
# 		else:
# 			print v
# 			t += 1
# 		print '======================'


