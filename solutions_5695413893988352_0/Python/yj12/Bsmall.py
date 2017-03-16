def solve(line):
    A = []
    B = []

    code = line[0]
    jam = line[1]
    print '--------------------', code, jam
    
    aidx = [i for i, a in enumerate(code) if a != '?']
    bidx = [i for i, b in enumerate(jam) if b != '?']
    
    if len(code) == 1:
	biggest = 9
    elif len(code) == 2:
	biggest = 99
    else:
	biggest = 999

    for i in range(biggest+1):
	test = str(i)
	finlen = len(code)
	while len(test) < len(code):
	    test = '0' + test
	
	keep = True
	for ai in aidx:
	    if test[ai] == code[ai]:
		continue
	    else:
		keep = False
	if keep:
	    A.append(test)

	keep = True
	for bi in bidx:
	    if test[bi] == jam[bi]:
		continue
	    else:
		keep = False
	if keep:
	    B.append(test)
    
    smalldiff = float('Inf')
    Aans = A[0]
    Bans = B[0]
    for AA in A:
	for BB in B:
	    if abs(int(AA)-int(BB)) < smalldiff:
		smalldiff = abs(int(AA)-int(BB))
		Aans = AA
		Bans = BB
    return Aans + ' ' +  Bans

file = 'B-small-attempt1.in'
fileout = 'B-small-attempt1.out'

cases = []
with open(file) as f:
    T = int(f.readline())
    # read in test cases
    for t in range(T):
	cases.append(f.readline().strip().split(' '))

f = open(fileout, 'w')
# solve each test case
for i, c in enumerate(cases):
    soln = solve(c)
    print soln
    f.write('Case #' + str(i+1) + ': ' + str(soln) + '\n')
f.close()