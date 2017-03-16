from random import randint
def fac(n):
	for i in xrange(2, 11):
		if n % i == 0:
			return i
	return 0
input()
n, l = map(int, raw_input().split())
print "Case #1:"
used = set()
for hhh in xrange(l):
	while True:
		i = '1' + bin(randint(0, (1 << n - 2) - 1))[2:].zfill(n - 2) + '1'
		if i in used:
			continue
		hue = []
		for j in xrange(2, 11):
			m = fac(int(i, j))
			if m: hue.append(m)
			else: break
		else:
			print i,
			for x in hue:
				print x,
			print
			used.add(i)
			break