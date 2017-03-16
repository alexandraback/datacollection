from fractions import gcd
from math import sqrt
t = int(raw_input())
count = 1
while count <= t:
	s = raw_input()
	s = s.split("/")
	p = int(s[0])
	q = int(s[1])
	x = gcd(p, q)
	p /= x
	q /= x
	n = 0
	m = 0
	for i in range (0, 41):
		if int(pow(2, i)) == q:
			n = i
			break
	if p == 1:
		m = 0
	else:
		for i in range (0, 41):
			if int(pow(2, i)) > p:
				m = i - 1
				break
	if p == q:
		print("Case #" + str(count) + ": 1")
	elif p > q:
		print("Case #" + str(count) + ": impossible")
	elif n == 0:
		print("Case #" + str(count) + ": impossible")
	else:
		print("Case #" + str(count) + ": " + str(n - m))
	count += 1
