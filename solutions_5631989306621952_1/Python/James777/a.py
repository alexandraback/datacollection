import sys
import optparse

debug = True

def solve(data):
	if debug:
		print '[+] input data %s' % data

	ret = [data[0]]
	for i in range(1,len(data)):
		if data[i] >= ret[0]:
			ret.insert(0,data[i])
		else:
			ret.append(data[i])

	return str(''.join(ret))

def readData(infile):
	line = infile.readline().strip()
	return line

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
