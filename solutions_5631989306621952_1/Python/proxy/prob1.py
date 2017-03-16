infile = open("input", "r")
outfile = open("output", "w")

lines = infile.readlines()
linenum = lines[0]

for j,line in enumerate(lines[1:]):
	word = ""
	for i,c in enumerate(line.rstrip()):
		if i==0:
			word = c
		else:
			if c >= word[0]:
				word = c + word
			else:
				word = word + c
	outfile.write("Case #" + str(j+1) + ": " + word + "\n")
