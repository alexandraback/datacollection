from collections import defaultdict



def solve(line):
    lets = defaultdict(int)
    for a in line:
	lets[a] += 1
    
    ans = []
    def update(letter, number):

	for ll in ndict[number]:
	    lets[ll] -= 1

	remove = []
	for k, v in lets.iteritems():
	    if lets[k] == 0:
		remove.append(k)
	    if lets[k] < 0:
		print 'error!!', k, v
	for r in remove:
	    lets.pop(r)
	ans.append(number)

    while 'Z' in lets:
      update('Z', 0)
    while  'W' in lets:
      update('W', 2)
    while  'X' in lets:
      update('X', 6)
    while 'G' in lets:
	update('G', 8)
    while 'U' in lets:
	update('U', 4)
    while 'H' in lets:
	update('H', 3)
    while 'O' in lets:
	update('O', 1)
    while 'F' in lets:
	update('F', 5)
    while 'V' in lets:
	update('V', 7)
    while 'N' in lets:
	update('N', 9)
	
    return ''.join(map(str, sorted(ans)))

file = 'A-large.in'
fileout = 'A-large.out'

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

ndict = []
for n in numbers:
    ndict.append(list(n))

cases = []
with open(file) as f:
    T = int(f.readline())
    # read in test cases
    for t in range(T):
	cases.append(f.readline().strip())

f = open(fileout, 'w')
# solve each test case
for i, c in enumerate(cases):
    soln = solve(c)
    print soln
    f.write('Case #' + str(i+1) + ': ' + str(soln) + '\n')
f.close()