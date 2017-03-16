import sys
import string
t = int(sys.stdin.readline())
for i in range(t):
	line = sys.stdin.readline().strip().split()
	n = int(line[0])
	s = int(line[1])
	p = int(line[2])
	count = 0
	for j in range(3, 3 + n):
		if (int(line[j]) >= 3 * p - 2):
			count += 1
		elif(s > 0 and int(line[j]) >= p and int(line[j]) >= 3 * p - 4):
			count += 1
			s -= 1
	print 'Case #' + str(i+1) + ': ' + str(count)