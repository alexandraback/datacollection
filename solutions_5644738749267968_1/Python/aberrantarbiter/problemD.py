def is_dominant(hers, his):
	return False not in [x > y for x, y in zip(hers, his)]

def solve(hers, his):
	while not is_dominant(hers, his):
		hers = hers[1:]
		his = his[:-1]
	return len(hers)

def solve_normal(hers, his):
	pts = 0
	while len(hers) > 0:
		if hers[-1] > his[-1]:
			pts += 1
			hers = hers[:-1]
			his = his[1:]
		else:
			i = 0
			while his[i] < hers[0]:
				i += 1
			his = [x for x in his if x != his[i]]
			hers = hers[1:]
	return pts





def main():
	with open('input.txt','r') as f:
		problems = int(f.readline())
		answers = []
		for i in xrange(problems):
			f.readline()
			h1 = f.readline()
			h2 = f.readline()
			hers = sorted([float(x) for x in h1.split(' ')])
			his = sorted([float(x) for x in h2.split(' ')])
			normal = solve_normal(hers, his)
			deceit = solve(hers, his)
			answers.append("Case #%d: %d %d" % (i+1, deceit, normal))
		with open('output.txt','w') as fout:
			fout.write('\n'.join(answers))




if __name__ == "__main__":
	main()