import sys
import time


def get_pancake_flips(pline):
	if len(pline) == 0:
		return 0
	if len(pline) == 1:
		if pline == "+":
			return 0
		else:
			return 1

	cur = pline[0]
	flips = 0
	# True means +
	state = True if cur == '+' else False

	for p in pline[1:]:
		if p != cur:
			flips += 1
			state = not state
			cur = p

	# final flip to all +
	if not state:
		flips += 1

	return flips

if __name__ == '__main__':
	start_time = time.time()

	data = file(sys.argv[1], "rb").read()
	lines = data.split('\n')
	out = file(sys.argv[1] + "-sol.dat", "wb")

	for i in xrange(int(lines[0])):
		pline = lines[i+1].strip()
		try:
			out.write("Case #%d: %d\n" % (i + 1, get_pancake_flips(pline)))
		except:
			print "exception in line %d" % i+1
			raise

	out.close()
	print "--- %s seconds ---" % (time.time() - start_time)
