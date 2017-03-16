
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

	for (e,lineinfo) in enumerate(flines[1:]):
		(k,c,s) = [int(x) for x in lineinfo.split()]
		# In the case where S=K, we can just check the first K tiles.
		# The first K are either all gold, or a copy of the original sequence.
		# Gold will only appear if gold was in the original sequence.
		if k!=s:
			print("Not the stated conditions of the small data set!")
			sys.exit(1)
		outf.write("Case #{0}: {1}\n".format(str(e+1), " ".join([str(x) for x in range(1,k+1)])))
	outf.close()

	sys.exit(0)

if __name__ == "__main__":
    main()
