from fractions import gcd
import math

case = int(raw_input())
for i in range(case):
	print "Case #%d:"%(i+1),
	mn = raw_input().split("/")
	m = int(mn[0])
	n = int(mn[1])
	#print m,n
	t = gcd(m,n)
	m = m/t
	n = n/t

	# is n 2^& ? 
	l = math.log(n,2.0)
	sim_l = round(l)
	if abs(l-sim_l)>10**-6:
		print "impossible"
		continue

	if 2*m >= n:
		#print "this is odd"
		print 1
		continue

	j = 1
	#print "Get to this?"
	while 2**j *m < n :
		j += 1
	print j

