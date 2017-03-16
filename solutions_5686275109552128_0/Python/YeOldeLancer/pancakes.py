# Google Code Jam 2015, Qualification Round
# Problem B. Infinite House of Pancakes
# Lance C. Simons

def split_biggest(diners):
	diners = diners[:]
	M = max(diners)
	diners.remove(M)
	diners.append(M/2)
	diners.append(M - M/2)
	return diners

def breakfast(diners):
	M = max(diners)
	if M < 3:
		return max(diners)

	return min( max(diners), 1 + breakfast(split_biggest(diners)) )


def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		num_diners = int(inf.next().strip())
		diners = map(int, inf.next().strip().split())
		outf.write("Case #%d: %d\n" % (i+1, breakfast(diners)))

if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))
