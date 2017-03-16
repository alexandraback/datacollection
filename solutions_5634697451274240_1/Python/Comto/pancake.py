def MakePlus(iCase,iEnd):
	if iEnd == 0 and iCase[0] == "+":
		return 0
	elif iCase[iEnd] == "+":
		return MakePlus(iCase,iEnd-1)
	else:
		return MakeMinus(iCase,iEnd) + 1

def MakeMinus(iCase,iEnd):
	if iEnd == 0 and iCase[0] == "-":
		return 0
	elif iCase[iEnd] == "-":
		return MakeMinus(iCase,iEnd-1)
	else:
		return MakePlus(iCase,iEnd) + 1

T = int(input())
for t in range(T):
	iCase = input().strip()
	print("Case #"+str(t+1)+":",MakePlus(iCase,len(iCase)-1))
