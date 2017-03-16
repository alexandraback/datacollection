import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",

	a, b, k = [int(j) for j in sys.stdin.readline().strip().split()]
	
	s = 0
	for p in range(a):
		for q in range(b):
			if p & q < k:
				s += 1
	print s
