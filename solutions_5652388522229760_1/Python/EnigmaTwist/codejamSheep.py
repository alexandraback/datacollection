
import sys

with open(sys.argv[1]) as f:
	flines = [x.strip() for x in f.readlines()]

if len(flines) != int(flines[0])+1:
	print("Error! First line isn't equal to number of other lines?")
	print(len(flines))
	print(int(flines[0])+1)
	sys.exit(1)

inputNums = [int(x) for x in flines[1:]]

outf = open(sys.argv[2],"w")

for (e,n) in enumerate(inputNums):
	if n==0:
		outf.write("Case #{0}: {1}\n".format(str(e+1), "INSOMNIA"))
		continue
	seenDigits = set()
	lastNum = n
	seenDigits |= set(str(lastNum))
	templist = [n]
	while len(seenDigits)<10:
		lastNum += n
		seenDigits |= set(str(lastNum))
		templist.append(int(lastNum))
	#outf.write("Case #{0}: {1} {2}\n".format(e+1, lastNum, templist))
	outf.write("Case #{0}: {1}\n".format(e+1, lastNum))

outf.close()

sys.exit(0)

