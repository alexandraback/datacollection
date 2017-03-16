from random import *

divi = []

def check(x):
	for v in divi:
		if (x%v == 0 and v!=x):
			return v
	return -1

for i in range(2,10000):

	ok = True

	k = 2
	while k*k <= i:
		if (i%k == 0 and i != k):
			ok = False; break
		k+=1

	if (ok): divi.append(i)


seen = set()

def getvalid(m):
	while (True):
		n = randint(1<<(m-1) , (1<<(m)) - 1)
		if (n%2 == 0): continue

		if (n in seen):
			continue

		seen.add(n)

		b = bin(n)[2:]

		A = []

		ok = True

		for i in range(2,11):
			cur = 0
			for c in b:
				cur = cur*i
				cur += ord(c) - ord('0')

			z = check(cur)
			if (z > 0):
				A.append(z)
			else:
				ok = False
				break
		if (ok):
			return (b,A)

n = input()
Z = input()

s = "%s"+" %d"*9

print "Case #1:"

for i in range(Z):
	k = getvalid(n)

	t = (k[0],)
	for e in k[1]:
		t += (e,)
	
	print s%t



