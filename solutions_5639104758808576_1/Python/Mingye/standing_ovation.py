import sys

def solve(smax, digits):
	total, friends = 0, 0
	for i in range(smax+1):
		if total < i:
			total += 1
			friends += 1
		total += int(digits[i])
	return friends

def run():
	with open(sys.argv[1]) as f:
		n = int(f.readline())
		for i in range(n):
			line = f.readline()

			smax, digits = line.split()
			result = solve(int(smax), digits)
			print "Case #%d: %d" % (i+1, result)

run()
