from math import factorial
results = [0 for x in xrange(2000005)]
def purge():
	for i in xrange(0, 2000005):
		results[i] = 0

foo = file("cs.in", "r");
bar = file("cs.out", "w");
tests = int(foo.readline())

for i in xrange(0, tests):
	purge()
	total = 0
	temp = foo.readline().split()
	bound = []
	for j in [0, 1]:
		bound.append(int(temp[j]))
	for j in xrange(bound[0], bound[1]+1):
		best = int(j)
		lol = str(j)
		for k in xrange(1, len(str(j))):
			lol = lol[-1] + lol[:-1]
			if (int(lol) < best):
				 best = int(lol)
		results[best] = results[best] + 1
	for p in xrange(0, 2000005):
		if (results[p] > 1):
			argh = factorial(results[p])
			argh = argh / 2;
			argh = argh / factorial(results[p]-2)
			total += argh
	bar.write("Case #" + str(i+1) + ": " + str(total) + '\n')
