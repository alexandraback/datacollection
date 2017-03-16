import sys

def main():
	name, pathin, pathout = sys.argv

	filein = open(pathin)
	fileout = open(pathout,'w')

	total = int(filein.readline())
	results = []
	for case in range(total):
		seq = filein.readline().split()[0]
		results.append(solve(seq))


	for i, result in enumerate(results):
		fileout.write('Case #%s: %s\n'%(i+1, result))


def flip(seq):
	results = []
	for i in range(len(seq)):
		if seq[i] == '-':
			results.append('+')
		else:
			results.append('-')
	return ''.join(results)


def solve(seq):
	
	hd = {'+':0, '-':1}
	sd = {'+':1, '-':0}

	def happy(seq):
		if seq in hd:
			return hd[seq]

		if seq[-1] == '-':
			if seq[0] == '-':
				result = 1 + happy(flip(seq))
			else:
				result = 1 + sad(seq[:-1])

		else:
			result = happy(seq[:-1])

		hd[seq] = result
		return result

	def sad(seq):
		if seq in sd:
			return sd[seq]

		if seq[-1] == '+':
			if seq[0] == '+':
				result = 1 + sad(flip(seq))
			else:
				result = 1 + happy(seq[:-1])

		else:
			result = sad(seq[:-1])

		sd[seq] = result
		return result

	return happy(seq)





if __name__ == '__main__':
	main()