from collections import defaultdict
import fileinput
stdin = fileinput.input()

def solveCase():
	S = next(stdin)[:-1]
	C = defaultdict(int)
	for s in S:
		C[s] += 1
	c = [0]*10
	c[0] = C['Z']
	c[2] = C['W']
	c[4] = C['U']
	c[6] = C['X']
	c[8] = C['G']
	c[1] = C['O']-c[0]-c[2]-c[4]
	c[3] = C['H']-c[8]
	c[7] = C['S']-c[6]
	c[5] = C['V']-c[7]
	c[9] = C['I']-c[5]-c[6]-c[8]
	return "".join(str(i)*k for i,k in enumerate(c))

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))