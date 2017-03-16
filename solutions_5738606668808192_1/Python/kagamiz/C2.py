import sys
import random

N = int(sys.argv[1])
J = int(sys.argv[2])
l = []

while (J):
	s = "1"
	for __ in range(N - 2):
		if random.randint(0, 1) == 0:
			s += "0"
		else :
			s += "1"
	s += "1"

	evidence = [0, 0, 0, 0, 0, 0, 0, 0, 0]
	ok = True
	for i in xrange(2, 11):
		M = 0
		for j in range(N):
			M = M * i + int(s[j])

		j = 2
		check = False
		while (j <= 100):
			if (M % j == 0):
				evidence[i - 2] = j
				check = True
				break
			j += 1

		if (check == False):
			ok = False
			break

	if (ok and s not in l):
		print "%s" % s,
		for x in xrange(0, 9) :
			if (x != 8):
				print "%d" % evidence[x],
			else :
				print "%d" % evidence[x]
		J -= 1
		l.append(s)

