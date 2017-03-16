import sys
import time


def print_placements(k, c, s):
	if s < k:
		return "IMPOSSIBLE"

	if s == 1:
		return "1"

	kc = k**c
	dist = kc / (s-1)
	if kc % (s - 1) == 0:
		dist -= 1

	placements = []
	for i in xrange(s):
		placements.append(str(1 + i * dist))

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
