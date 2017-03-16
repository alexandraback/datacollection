inp = open("file3.txt").read().splitlines()
outp = open("out3.txt","w")


def isset(mlist,mlist2):
	msum = 0
	prodlist = [1,mlist[0],mlist[1],mlist[2],mlist[0]*mlist[1]*mlist[2],mlist[0]*mlist[1],mlist[0]*mlist[2],mlist[1]*mlist[2]]
	for i in mlist2:
		if prodlist.count(i) == 0:
			return False
	return True

def mtest(mlist):
	for M1 in range(5,1,-1):
		for M2 in range(5,1,-1):
			for M3 in range(2,6):
				if isset([M1,M2,M3],mlist):
					return [M1,M2,M3]
	return [0,0,0]

outp.write("Case #1:\n")

for i in range(2,len(inp)):
	mlist = mtest(list(map(int,inp[i].split())))
	s = ''
	for j in mlist:
		s += str(j)
	outp.write(s+"\n")
	
