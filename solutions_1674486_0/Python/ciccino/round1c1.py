import re

def bsg(bg, g, state):
	if state[bg] == 1:
		return 1
	else:
		state[bg] = 1

	if g.has_key(bg):
		inp = g[bg]
		for i in range(len(inp)):
			ret = bsg(inp[i], g, state)
			if ret == 1:
				return 1
	return 0

def di(begin, inh, n):
	state = {}
	for i in range(n):
		state[i + 1] = 0
	while len(begin) > 0:
		tmp = inh
		ts = state.copy()
		#print ts
		bg = begin.pop()
		ret = bsg(bg, inh, ts)
		if ret == 1:
			return 1
	return 0


def round1c1(filepath):
	f = open(filepath, "r+")
	infile = re.split('in', filepath)
	outfile = infile[0] + "out"
	print outfile
	o = open(outfile, "w+")
	#number of test cases
	t = int(f.readline())

	for i in range(t):
		line = f.readline()
		n = int(line)
		#print n
		inh = {}
		begin = []
		for j in range(n):
			line = f.readline()
			sl = re.split(" ", line)
			#print sl
			m = int(sl[0])
			for k in range(m):
				if inh.has_key(int(sl[k + 1])):
					inh[int(sl[k + 1])].append(j + 1)
				else:
					inh[int(sl[k + 1])] = [j + 1]
			if m == 0:
				begin.append(j + 1)
		print inh
		result = di(begin, inh, n)
		if result == 1:
			retstr = "Yes"
		else:
			retstr = "No"
		#result = recycledNumbers(sl[0], sl[1], len(sl[0]))
		buf = "Case #" + str(i + 1) + ": " + retstr
		i = i + 1
		print buf
		o.write(buf + '\n')
	f.close()
	o.close()

round1c1("./A-small-attempt2.in")
#round1c1("./A-large.in")