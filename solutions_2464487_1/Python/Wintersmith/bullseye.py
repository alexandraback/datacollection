def sum_rings(rings, radius):
	return (rings)*(2*radius + 2*rings - 1)

def get_size(radius, paint, lo=0, hi=2*10**18):
	midpoint = (hi + lo) / 2
	painted = sum_rings(midpoint, radius)
	if painted == paint:
		return midpoint
	elif painted < paint:
		if sum_rings(midpoint + 1, radius) > paint:
			return midpoint
		else:
			return get_size(radius, paint, midpoint+1, hi)
	else:
		if sum_rings(midpoint - 1, radius) < paint:
			return midpoint - 1
		else:
			return get_size(radius, paint, lo, midpoint-1)

if __name__=='__main__':
	import argparse
	parser = argparse.ArgumentParser(description='Finds amount of cocentric circles that can be painted.')
	parser.add_argument('--verbose', '-v', action='store_true')
	parser.add_argument('infile', type=str, help='in file')
	parser.add_argument('outfile', type=str, nargs="?", help='out file (defaults to infile with extension changed to .out)')
	args = parser.parse_args()

	infile = open(args.infile, "r")
	outfile = open(args.outfile if args.outfile is not None else args.infile.rsplit(".")[0]+".out", "w")
	tests = int(infile.readline())
	for i in range(tests):
		radius, paint = [int(j) for j in infile.readline().split(" ")]
		s = "Case #%d: %d"%(i+1, get_size(radius, paint))
		if args.verbose:
			print s
		outfile.write(s + ("\n" if i < tests-1 else ""))
	infile.close()
	outfile.close()