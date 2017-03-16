import re
import copy

def tb(t, b):
	if len(t) == 0 or len(b) == 0:
		return 0
	toy = t[0]
	box = b[0]
	match = 0
	#print " ----- "
	#print t
	#print b
	if toy[0] != box[0]:
		#first t:
		#tmpt.pop(0)
		#tmpb.pop(0)
		tmpt = copy.deepcopy(t)
		tmpb = copy.deepcopy(b)
		tmpt.pop(0)
		rettoy = tb(tmpt, tmpb)
		b.pop(0)
		retbox = tb(t, b)
		if retbox > rettoy:
			return retbox
		else:
			return rettoy
	else:
		if toy[1] > box[1]:
			match = box[1]
			b.pop(0)
			t[0][1] = t[0][1] - match
			ret = tb(t, b)
			return match + ret
		elif toy[1] < box[1]:
			match = toy[1]
			t.pop(0)
			b[0][1] = b[0][1] - match
			ret = tb(t, b)
			return match + ret
		else:
			b.pop(0)
			t.pop(0)
			match = toy[1]
			ret = tb(t, b)
			return match + ret
	return 0


def round1c3(filepath):
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
		n = int(sl[0])
		m = int(sl[1])
		line = f.readline()
		sl = re.split(" ", line)
		t = []
		toyt = {}
		for j in range(n):
			t.append([int(sl[j * 2 + 1]), int(sl[j * 2])])
			toyt[int(sl[j * 2 + 1])] = 1
		line = f.readline()
		sl = re.split(" ", line)
		b = []
		for j in range(m):
			if toyt.has_key(int(sl[j * 2 + 1])):
				b.append([int(sl[j * 2 + 1]), int(sl[j * 2])])

		#print t
		#print b
		result = tb(t, b)
		#result = recycledNumbers(sl[0], sl[1], len(sl[0]))
		buf = "Case #" + str(i + 1) + ": " + str(result)
		i = i + 1
		print buf
		o.write(buf + '\n')
	f.close()
	o.close()

round1c3("./C-small-attempt1.in")
#round1c3("./c-test.in")