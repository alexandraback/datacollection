from collections import defaultdict

def solve(line):
    ans = 0
    N = len(line)
    
    def findfake(binstr):
	reals = []
	fake = 0

	for i, b in enumerate(binstr):
	    b = int(b)
	    if b == 1:
		reals.append(line[i])
	
	if len(reals) == 0:
	    return 0
	
	reals = zip(*reals)
	r1 = set(reals[0])
	r2 = set(reals[1])

	for entry in line:
	    if entry[0] not in r1 or entry[1] not in r2:
		return -5

	    if entry[0] in r1 and entry[1] in r2:
		fake +=1
	
	return fake - len(reals[0])
	

    maxfake = 0
    for i in range(2**N):
	binstr = "{0:b}".format(i).zfill(N)
#	while len(binstr) < N:
#	    binstr = '0' + binstr
	nfake = findfake(binstr)
	maxfake = max(maxfake, nfake)
    return maxfake

file = 'C-small-attempt2.in'
fileout = 'C-small-attempt2.out'
#file = 'test.in'
#fileout = 'test.out'

cases = []
with open(file) as f:
    T = int(f.readline())
    # read in test cases
    for t in range(T):
	N = int(f.readline())
	case = []
	for n in range(N):
	    case.append(f.readline().strip().split(' '))
	cases.append(case)

f = open(fileout, 'w')
# solve each test case
for i, c in enumerate(cases):
    soln = solve(c)
    print soln
    f.write('Case #' + str(i+1) + ': ' + str(soln) + '\n')
f.close()