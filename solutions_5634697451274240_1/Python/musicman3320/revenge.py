fin = open('B-large.in', 'r')
fout = open('B-large.out','w')


numlines = int(fin.readline().rstrip())

for line in range(numlines):
	val = str(fin.readline().rstrip())
	vals = [(c=="+") for c in val]
	
	result = 0
	while(not(all(vals))):
		result = result + 1
		if vals[0]:
			j = 0
			while j < len(vals) and vals[j]:
				vals[j] = False
				j = j + 1
		else:
			j = 0
			while j < len(vals) and not(vals[j]):
				vals[j] = True
				j = j + 1
	
	outstr = "Case #" + str(line+1) + ": " + str(result) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)


