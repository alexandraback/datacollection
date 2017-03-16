def is_dominant(hers, his):
	return False not in [x > y for x, y in zip(hers, his)]

def solve(hers, his):
	while not is_dominant(hers, his):
		hers = hers[1:]
		his = his[:-1]
	return len(hers)

def solve_normal(hers, his):
	if len(hers) == 0:
		return 0
	if hers[-1] > his[-1]:
		return 1 + solve_normal(hers[:-1], his[1:])
	else:
		i = 0
		while his[i] < hers[0]:
			i += 1
		new_his = [x for x in his if x != his[i]]
		return solve_normal(hers[1:], new_his)





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