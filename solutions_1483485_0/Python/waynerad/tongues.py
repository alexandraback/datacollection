def do_tongues(input_file, output_file):
	alphamap = {'y':'a', 'n':'b', 'f':'c', 'i':'d', 'c':'e', 'w':'f', 'l':'g', 'b':'h', 'k':'i', 'u':'j', 'o':'k', 'm':'l', 'x':'m', 's':'n', 'e':'o', 'v':'p', 'z':'q', 'p':'r', 'd':'s', 'r':'t', 'j':'u', 'g':'v', 't':'w', 'h':'x', 'a':'y', 'q':'z', ' ':' '}
	fout = open(output_file, 'w')
	fin = open(input_file, 'r')
	count_line = fin.readline()
	count_line = count_line.strip()
	line_count = int(count_line)
	for lnum in range(line_count):
		dataline = fin.readline()
		dataline = dataline.strip()
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ')
		for i in range(len(dataline)):
			fout.write(alphamap[dataline[i]])
		fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'A-small-attempt0'
	input_file = runname + '.in'
	output_file = runname + '.out'
	do_tongues(input_file, output_file)

main()
