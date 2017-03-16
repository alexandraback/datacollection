import re

def password(a, b, p):
	#calculate the optimal
	#option 1
	exp = 0.0
	sucp = 1
	for i in range(a):
		sucp = sucp * p[i]
	exp = sucp * (b - a + 1) + (1 - sucp) * (b - a + 1 + b + 1)
	#print "option 1:" + str(exp)
	#option 2
	#exp2 = exp1
	for i in range(a):
		sucp = sucp / p[a - i - 1]
		tmp = sucp * (b - a + 1 + 2 * (i + 1)) + (1 - sucp) * (b - a + 1 + b + 1 + 2 * (i + 1))
		#print "tmp : " + str(tmp)
		if tmp < exp:
			exp = tmp
	#print "option 2:" + str(exp)
	#option 3
	#exp3 = (b + 2)
	if (exp > (b + 2)):
		exp = b + 2

	return exp

def round1a1(filepath):
	f = open(filepath, 'r+')
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
		b = int(sl[1])
		line = f.readline()
		sl = re.split(" ", line)
		p = []
		for j in range(a):
			p.append(float(sl[j]))
		#print str(a) + str(b) + str(p)
		result = password(a, b, p)
		#result = recycledNumbers(sl[0], sl[1], len(sl[0]))
		buf = "Case #" + str(i + 1) + ": " + str(result)
		i = i + 1
		print buf
		o.write(buf + '\n')
	f.close()
	o.close()

round1a1("./A-large.in")