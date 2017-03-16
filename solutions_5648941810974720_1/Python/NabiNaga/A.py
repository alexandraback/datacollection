from collections import Counter

def solve(line):
	c = Counter(line)
	counts = [0]*10
	counts[0] = c['Z']
	counts[6] = c['X']
	counts[4] = c['U']
	counts[8] = c['G']
	counts[2] = c['W']
	counts[5] = c['F'] - counts[4]
	counts[7] = c['V'] - counts[5]
	counts[3] = c['R'] - counts[0] - counts[4]
	counts[9] = c['I'] - counts[6] - counts[8] - counts[5]
	counts[1] = c['N'] - counts[7] - 2*counts[9]
	ans = []
	for i, c in enumerate(counts):
		ans.append(str(i)*c)
	return ''.join(ans)

output = []
with open('A_input.txt') as f:
	t = int(f.readline())
	for i,line in enumerate(f):
		output.append("Case #%d: %s\n" % (i+1,solve(line.strip())))

with open('A_output.txt','w') as f:
	for line in output:
		print line,
		f.write(line)

'''
Z - 0
X - 6
U - 4
G - 8
W - 2

Sub 4's F
Remaining F is 5

Sub 5's V
Remaining V is 7

Sub 0's and 4's R
Remaining R is 3

Sub 6,8,5 I
Remaining I is 9

Sub 1 N for 7's, 2 N for 9's
Remaining N is 1
'''