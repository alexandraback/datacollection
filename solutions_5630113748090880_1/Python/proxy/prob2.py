infile = open("input", "r")
outfile = open("output", "w")

cases = infile.readline()

for case in range(int(cases)):
	N = infile.readline()
	appears = [0]*2501
	for i in range(2*int(N)-1):
		line = infile.readline()
		for j in line.split(' '):
			number = int(j)
			appears[number] += 1
	outfile.write("Case #" + str(int(case+1)) + ":"),
	for k in range(2501):	
		if appears[k]%2 != 0:
			outfile.write(" " + str(k)),
	
	outfile.write("\n"),
