def calc_min_hits(r, c, w):
	counts = 0

	# for all non final lines, do overlap len while we can
	counts += (r - 1) * (c / w)

	# for the last line, we can do the overlap until last. now we can
	# do this until the last part where we have remainder + w
	rem = c % w
	counts += (c - rem - w) / w

	# we want to bound him
	if rem > 0:
		counts += 1

	# now the battle
	counts += w

	return counts

if __name__ == '__main__':
	import sys
	import time

	start_time = time.time()

	data = file(sys.argv[1], "rb").read()
	lines = data.split('\n')
	out = file(sys.argv[1] + "-sol.dat", "wb")

	for i in xrange(int(lines[0])):
		r, c, w = lines[i+1].strip().split(" ")
		r = int(r)
		c = int(c)
		w = int(w)
		out.write("Case #%d: %d\n" % (i + 1, calc_min_hits(r, c, w)))

	out.close()
	print "--- %s seconds ---" % (time.time() - start_time)
