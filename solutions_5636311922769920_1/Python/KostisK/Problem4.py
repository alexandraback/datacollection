import itertools
import math

fd = open("in4", "r")

lines = fd.readlines()

testcases = int(lines[0])



fout = open("out4", "w")

for line_ind in xrange(1,len(lines)):
	line  = lines[line_ind]

	fout.write("Case #" + str(line_ind) + ": ")

	words = line.split()

	K = int(words[0])
	C = int(words[1])
	S = int(words[2])

	if(C == 1):
		if(S < K):
			fout.write("IMPOSSIBLE\n")
		else:
			sol = [x  for x in range(1,int(line.split()[0]) + 1)]
			fout.write(" ".join(map(str, sol)) + "\n")
	elif(S < math.log(K, C)):
		fout.write("IMPOSSIBLE\n")
	else:
		ind_s = 0
		sol = []
		while(ind_s < S):
			le_num = 1
			for i in xrange(1,C+1):
				le_num += ind_s * (K ** (C - i))
				ind_s += 1
			sol.append(le_num)
		fout.write(" ".join(map(str, sol)) + "\n")

