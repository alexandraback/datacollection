import sys
from collections import Counter

# python.exe cjsoldier.py "..\..\..\Downloads\B-small-attempt0.in" cjsoldiersmall.out


def main():

	with open(sys.argv[1]) as f:
		flines = [x.strip() for x in f.readlines()]

	if len(flines[-1])==0:
		flines = flines[:-1]

	outf = open(sys.argv[2],"w")

	numCases = int(flines[0])
	cases = [[]]*numCases
	casenum = 0
	isN = True
	linectr = 0
	soldierctr = Counter()
	n=0
	for fl in flines[1:]:
		print(fl)
		if isN:
			n = int(fl)
			casenum += 1
			isN = False
			linectr = 0
			soldierctr = Counter()
			continue
		linectr += 1
		soldierctr.update([int(x) for x in fl.split()])
		if linectr == 2*n - 1:
			leftovers = []
			for x in soldierctr:
				if soldierctr[x]%2==1:
					leftovers.append(x)
			outf.write("Case #{}: {}\n".format(str(casenum), " ".join([str(x) for x in sorted(leftovers)])))
			isN = True
	
	outf.close()

	sys.exit(0)

if __name__ == "__main__":
    main()





