import sys

t = int(sys.stdin.readline())

for i in range(t) :
	res = 0
	line = sys.stdin.readline().strip().split()
	a, b = int(line[0]), int(line[1])

	for num in range(a, b) :
		strnum = str(num)

		n = len(strnum)
		strnum *= 2
		x = set()
		for j in range(1, n) :
			m = int(strnum[j : j + n])
			
			if m not in x and m > num and m > a and m <= b:
				res += 1
			x.add(m)

	print "Case #%d:" % (i+1), res