# Google Code Jam 2015, Qualification Round
# Problem A. Standing Ovation
# Lance C. Simons

def astroturf(audience):
	people_needed = 0
	people_cheering = 0

	for c in audience:
		people_cheering += int(c)

		if people_cheering > 0:
			people_cheering -= 1
		else:
			people_needed += 1

	return people_needed


def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		max_shyness,audience = inf.next().strip().split()
		outf.write("Case #%d: %d\n" % (i+1, astroturf(audience)))

if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))
