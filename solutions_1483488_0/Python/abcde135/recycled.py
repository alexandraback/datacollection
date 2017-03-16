def write_case(n, s, f):
    f.write("Case #%i: %s\n" % (n, s))

def get_recycles(d):
	x = str(d)
	strperm = [x[i:] + x[:i] for i in range(len(x))]
	recycles = set([int(t) for t in strperm])

	return recycles

def count_pairs(A, B):
	numbers = set()
	count = 0
	for d in range(A, B+1):
		if d in numbers:
			continue

		recycles = [t for t in get_recycles(d) if A <= t <= B]
		n = len(recycles)
		count += n*(n-1)/2
		numbers.update(recycles)

	return count

def solve(infilename, outfilename):
	f = open(infilename)
	g = open(outfilename, 'w')

	T = int(f.readline())
	for n in range(T):
		(A, B) = [int(x) for x in f.readline().split()]
		count = count_pairs(A, B)
		write_case(n+1, str(count), g)

	f.close()
	g.close()

if __name__ == "__main__":
#	solve('recycled-sample.in', 'recycled-sample.out')
#	solve('recycled-sample-large.in', 'recycled-sample-large.out')
	solve('C-small-attempt0.in', 'C-small-attempt0.out')
