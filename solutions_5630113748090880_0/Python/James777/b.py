import sys
import optparse

debug = False

def solve(data):
	N = data[0]
	lines = data[1]
	if debug:
		print '[+] input data %d %s' % (N, lines)

	heights = [0 for i in range(2501)]

	for line in lines:
		for item in line:
			heights[item] += 1

	ret = []
	for i in range(1,2501):
		if heights[i] % 2 != 0:
			ret.append(str(i))

	if debug:
		print '[+] heights %s' % heights
	return ' '.join(ret)

def readData(infile):
	N = int(infile.readline().strip())
	lines = []
	for i in range(N*2-1):
		lines.append(map(int,infile.readline().strip().split()))
	return N, lines

def howto():
	usage = ' -i <input file> [-o <output file>]'
	parser = optparse.OptionParser(sys.argv[0] + usage)
	parser.add_option(
		'-i', dest='infile', type='string', help='specify infile name')
	parser.add_option(
		'-o', dest='outfile', type='string', help='specify outfile name')
	(options, args) = parser.parse_args()
	if options.infile is None:
		print parser.usage
	return options.infile, options.outfile

if __name__ == '__main__':
	infile, outfile = howto()
	if infile is None:
		exit()

	infile = open(infile, 'r')
	if outfile is not None:
		outfile = open(outfile, 'w')

	T = int(infile.readline().strip())
	for caseN in xrange(1, T + 1):
		data = readData(infile)
		result = solve(data)
		resultForm = 'Case #%i: %s\n' % (caseN, result)

		if outfile:
			outfile.write(resultForm)
		else:
			print resultForm

	infile.close()
	if outfile is not None:
		outfile.close()
