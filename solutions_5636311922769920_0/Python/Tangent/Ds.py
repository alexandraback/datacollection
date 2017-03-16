import sys

def main():
	name, pathin, pathout = sys.argv

	filein = open(pathin)
	fileout = open(pathout,'w')

	total = int(filein.readline())
	results = []
	for case in range(total):
		K, C, S = [int(_) for _ in filein.readline().split()]
		results.append(solve(K,C,S))

	for i, result in enumerate(results):
		fileout.write('Case #%s: %s\n'%(i+1, ' '.join(result)))

def solve(K,C,S):
	return [str(i+1) for i in range(K)]

if __name__ == '__main__':
	main()