import sys

def main():
	name, pathin, pathout = sys.argv

	filein = open(pathin)
	fileout = open(pathout,'w')

	total = int(filein.readline())
	results = []
	for case in range(total):
		n = int(filein.readline())
		results.append(solve(n))

	for i, result in enumerate(results):
		fileout.write('Case #%s: %s\n'%(i+1, result))

def solve(n):

	if not n:
		return 'INSOMNIA'

	dset = set()
	i = 1
	while True:
		number = str(n*i)
		for bit in number:
			if bit not in dset:
				dset.add(bit)
		if len(dset) == 10:
			break
		i += 1
	return number

if __name__ == '__main__':
	main()

