import sys
from fractions import gcd

t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",

	p, q = [int(j) for j in sys.stdin.readline().strip().split("/")]
	
	g = gcd(p, q)
	p = p // g
	q = q // g
	
	j = 1
	k = 2
	found = False
	while (not found) and (j <= 40):
		if (k >= q) and (k % q == 0):
			found = True
		else:
			j += 1
			k *= 2
			
	if not found:
		print "impossible"
		continue
		
	x = p * (k // q)
	
	j = 0
	while x < k:
		j += 1
		k = k // 2
		
	if j == 0:
		j = 1
		
	print j
