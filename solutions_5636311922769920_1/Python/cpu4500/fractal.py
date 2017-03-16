import sys
import time


def print_placements(k, c, s):
	if s < (k+1)/2:
		return "IMPOSSIBLE"

	if k == 1:
		return "1"

	kc = k**c
	dist = kc / (k-1)
	if kc % (k-1) == 0:
		dist -= 1

	placements = []
	ch = 2
	for i in xrange((k+1)/2):
		placements.append(str(ch))

		# we will have redundancy for uneven k
		if ch + dist * 2 > kc:
			ch += dist
		else:
			ch += 2 * dist

	return " ".join(placements)

if __name__ == '__main__':
	start_time = time.time()

	data = file(sys.argv[1], "rb").read()
	lines = data.split('\n')
	out = file(sys.argv[1] + "-sol.dat", "wb")

	for i in xrange(int(lines[0])):
		k, c, s = lines[i+1].split(" ")
		k = int(k)
		c = int(c)
		s = int(s)
		out.write("Case #%d: %s\n" % (i + 1, print_placements(k, c, s)))

	out.close()
	print "--- %s seconds ---" % (time.time() - start_time)
