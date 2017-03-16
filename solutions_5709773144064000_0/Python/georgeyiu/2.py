from parser import parse, split

def helper(test):
	c, f, x = test
	t = 0.0
	cps = 2.0
	while True:
		timetilwin = x/cps
		timetilfactory = c/cps
		if timetilwin < timetilfactory:
			return t + timetilwin
		t += timetilfactory
		if x/(cps+f) < ((x-c)/cps):
			cps += f
			continue
		return t + ((x-c)/cps)
	return 0

# schema here
schema = [(),[split(float)]]

num_tests, tests = parse(schema)
for case,test in enumerate(tests):
	sol = helper(test)
	print 'Case #{}: {}'.format(case+1, sol)
