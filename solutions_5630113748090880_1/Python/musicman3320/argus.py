fin = open('B-large.in', 'r')
fout = open('B-large.out','w')


numtests = int(fin.readline().rstrip())

for test in range(numtests):
	N = int(fin.readline().rstrip())
	
	heightCounts = [0]*2501
	for i in range(2*N-1):
		page = [int(h) for h in str(fin.readline().rstrip()).split(" ")]
		for h in page:
			heightCounts[h] = heightCounts[h] + 1
	
	result = []
	for h in range(len(heightCounts)):
		if heightCounts[h] % 2 == 1:
			result = result + [str(h)]
	
	outstr = "Case #" + str(test+1) + ": " + str(' '.join(result)) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)


