#import math
import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
	l = sys.stdin.readline().strip().split()
	letter = l[0]
	n = int(l[1])

	consecutive = 0
	s = 0
	for j in range(len(letter)):
		is_cons = (letter[j] != 'a') and (letter[j] != 'e') and (letter[j] != 'i') and (letter[j] != 'o') and (letter[j] != 'u')

		if is_cons:
			consecutive += 1
		else:
			consecutive = 0

		if consecutive >= n:
			a = j - n + 2
		else:
			if j == 0:
				a = 0
			else:
				a = prev_a

		prev_a = a

		s += a
		

	print "Case #" + str(i + 1) + ": " + str(s)
