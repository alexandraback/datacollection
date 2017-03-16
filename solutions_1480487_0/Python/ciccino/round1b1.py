import re

def sn(a, p):
	x = 0

	for i in range(len(p)):
		x = x + p[i]
	num = 0
	print p
	retval = []
	for i in range(len(p)):
		tmp = 2.0 * x - a * p[i]
		tmp = tmp / (a * x)
		if tmp < 0:
			tmp = 0
		retval.append(tmp * 100)
	ox = x
	for i in range(len(retval)):
		if retval[i] == 0:
			x = x - p[i]
			num = num + 1

	for i in range(len(p)):
		if retval[i] != 0:
			tmp = ox + x - (a - num) * p[i]
			tmp = (tmp * 1.0) / ((a - num) * ox)
			retval[i] = tmp * 100
	return retval

def round1b1(filepath):
	f = open(filepath, "r+")
	infile = re.split('in', filepath)
	outfile = infile[0] + "out"
	print outfile
	o = open(outfile, "w+")
	#number of test cases
	t = int(f.readline())

	for i in range(t):
		line = f.readline()
		sl = re.split(" ", line)
		a = int(sl[0])
		p = []
		for j in range(a):
			p.append(int(sl[j + 1]))
		#print str(a) + str(b) + str(p)
		result = sn(a, p)
		retstr = ""
		for k in range(len(result)):
			retstr = retstr + " " + str(result[k])
		#result = recycledNumbers(sl[0], sl[1], len(sl[0]))
		buf = "Case #" + str(i + 1) + ":" + retstr
		i = i + 1
		print buf
		o.write(buf + '\n')
	f.close()
	o.close()

round1b1("./A-small-attempt3.in")
#round1b2("./B-large.in")