def toLoc(arr,K,C):
	pos = 1
	for a in range(1,C+1):
		pos += arr[a-1]*K**(C-a)
	return pos

f = open('D-small-attempt0.in')
output = open('D-small-attempt0.out','w')
curr_line = f.readline()
numCases = int(curr_line)
for i in range(0,numCases):
	output.write("Case #%d:" %(i+1))
	curr_line = f.readline()
	inputs = curr_line.split(' ')
	K = int(inputs[0])
	C = int(inputs[1])
	S = int(inputs[2])
	if K > C*S:
		output.write(" IMPOSSIBLE")
	else:
		r = K%C
		m = K/C
		n = m
		if r > 0:
			n += 1
		locs = []
		for j in range(0,n):
			loc = []
			for k in range(0,C):
				loc.append(k+j*C)
			locs.append(loc)
		if r > 0:
			loc = locs.pop()
			for j in range(0,C-r):
				loc.pop()
			for j in range(0,C-r):
				loc.append(0)
			locs.append(loc)
		for l in locs:
			output.write(" %d" %toLoc(l,K,C))

	if i < numCases-1:
		output.write("\n")

