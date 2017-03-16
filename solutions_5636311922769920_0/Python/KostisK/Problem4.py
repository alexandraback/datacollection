import itertools

fd = open("in4", "r")

lines = fd.readlines()

testcases = int(lines[0])



fout = open("out4", "w")

for line_ind in xrange(1,len(lines)):
	line  = lines[line_ind]

	fout.write("Case #" + str(line_ind) + ": ")

	sol = [x  for x in range(1,int(line.split()[0]) + 1)]

	fout.write(" ".join(map(str, sol)) + "\n")

