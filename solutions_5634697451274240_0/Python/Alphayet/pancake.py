import sys

filename = sys.argv[1]

def find_first_region(pancakes):
	first_down = pancakes.index('-')
	last_down = first_down
	while last_down + 1 < len(pancakes):
		if pancakes[last_down + 1] == '-':
			last_down += 1
		else:
			break
	return first_down, last_down

with open(filename, 'r') as fh:
	T = int(fh.readline().strip())
	for t in range(T):
		pancakes = map(lambda x: x, fh.readline().strip())
		filps = 0
		while '-' in pancakes:
			rs, re = find_first_region(pancakes)
			pancakes[:re+1] = '+' * (re + 1)
			if rs == 0:
				filps += 1
			else:
				filps += 2
		print "Case #%d: %d" % (t+1, filps)


