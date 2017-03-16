fin = open('A-large.in', 'r')
fout = open('A-large.out','w')


numlines = int(fin.readline().rstrip())

for line in range(numlines):
	val = str(fin.readline().rstrip())
	
	result = ""
	for i in range(len(val)):
		if val[i] + result < result + val[i]:
			result = result + val[i]
		else:
			result = val[i] + result
	
	outstr = "Case #" + str(line+1) + ": " + str(result) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)


