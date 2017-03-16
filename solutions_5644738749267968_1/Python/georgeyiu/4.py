from parser import parse, split

def helper(test):
	_, n1, k1 = test
	n = sorted(n1)
	k = sorted(k1)
	# print n
	# print k
	war = 0
	for a in n:
		over = -1
		for i,b in enumerate(k):
			if b > a:
				over = i
				break
		if over >= 0:
			k.pop(over)
			continue
		war += 1
		k.pop()
	n = sorted(n1)
	k = sorted(k1)
	dwar = 0
	while len(n) > 0:
		if max(n) < max(k):
			n.pop(0)
			k.pop(-1)
		else:
			n.pop(-1)
			k.pop(-1)
			dwar += 1
	return '{} {}'.format(dwar, war)

# schema here
schema = [(),[int,split(float),split(float)]]

num_tests, tests = parse(schema)
for case,test in enumerate(tests):
	sol = helper(test)
	print 'Case #{}: {}'.format(case+1, sol)
