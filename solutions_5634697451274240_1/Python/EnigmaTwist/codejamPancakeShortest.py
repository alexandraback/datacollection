
import sys

def main():

	with open(sys.argv[1]) as f:
		flines = [x.strip() for x in f.readlines()]

	if len(flines) != int(flines[0])+1:
		print("Error! First line isn't equal to number of other lines?")
		print(len(flines))
		print(int(flines[0])+1)
		sys.exit(1)

	outf = open(sys.argv[2],"w")

	for (e,s) in enumerate(flines[1:]):
		if len(set(s) - set("+-"))!=0:
			print("Error! Line does not consist solely of +/-")
			print(s)
			sys.exit(1)
		flipctr = 0
		polarity = "+"
		for p in range(len(s)-1, -1, -1):
			if s[p] != polarity:
				flipctr += 1
				if polarity == "+":
					polarity = "-"
				else:
					polarity = "+"
		
		outf.write("Case #{0}: {1}\n".format(str(e+1), str(flipctr)))
	outf.close()

	sys.exit(0)

if __name__ == "__main__":
    main()
