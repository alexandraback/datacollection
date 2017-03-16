def solver (tempdata):
	n = int(tempdata)
	naomilist = [float(wt) for wt in inputfile.readline().rstrip("\n").split(" ")]
	kenlist = [float(wt) for wt in inputfile.readline().rstrip("\n").split(" ")]
	cheatscore = cheat(sorted(naomilist), sorted(kenlist), n)
	fairscore = fair(sorted(naomilist), sorted(kenlist), n)
	return "%i %i" % (cheatscore, fairscore)

def cheat (nlist, klist, n):
	cscore = 0
	while n>0:
		if klist[0]>nlist[0]:
			nlist.pop(0)
			klist.pop(n-1)
			n = n-1
		else:
			nlist.pop(0)
			klist.pop(0)
			cscore = cscore + 1
			n = n-1
	return cscore
	
def fair (nlist, klist, n):
	fscore = 0
	while n>0:
		if klist[n-1]>nlist[n-1]:
			nlist.pop(n-1)
			klist.pop(n-1)
			n = n-1
		else:
			nlist.pop(n-1)
			klist.pop(0)
			fscore = fscore + 1
			n = n-1
	return fscore
	
inputfile = open('D-large.in')
outputfile = open('D-large-done.txt', 'w')

numberofcases = inputfile.readline()     
for tempnumber in range(1, int(numberofcases)+1):
	tempdata = inputfile.readline().rstrip("\n")
	outputfile.write("Case #%i: %s\n" % (tempnumber, solver(tempdata)))
	
inputfile.close()
outputfile.close()