
import sys
from math import ceil

def main():

	with open(sys.argv[1]) as f:
		flines = [x.strip() for x in f.readlines()]

	if len(flines[-1])==0:
		flines = flines[:-1]
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
		if k==s:
			outf.write("Case #{0}: {1}\n".format(str(e+1), " ".join([str(x) for x in range(1,k+1)])))
			#print("Case #{0}: {1}\n".format(str(e+1), " ".join([str(x) for x in range(1,k+1)])))
			continue
		
		# Check if S is too small
		if s<ceil(k/c):
			outf.write("Case #{0}: {1}\n".format(str(e+1), "IMPOSSIBLE"))
			#print("Case #{0}: {1}\n".format(str(e+1), "IMPOSSIBLE"))
			continue
		
		tilesToCheck = []
		for i in range(0,k,c):
			tileNum = 0
			for (fpos, j) in enumerate(range(i,i+c)):
				if j>=k:
					break
				tileNum += j*(k**fpos)
			tilesToCheck.append(tileNum+1)
		
		
		
		outf.write("Case #{0}: {1}\n".format(str(e+1), " ".join([str(x) for x in tilesToCheck])))
		#print("Case #{0}: {1}\n".format(str(e+1), " ".join([str(x) for x in tilesToCheck])))
		
		
	outf.close()

	sys.exit(0)

if __name__ == "__main__":
    main()
