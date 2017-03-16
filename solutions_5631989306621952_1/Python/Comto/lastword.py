def solveIt(iStr):
	outStr = iStr[0]
	for i in range(1,len(iStr)):
		if iStr[i] >= outStr[0]:
			outStr = iStr[i] + outStr
		else:
			outStr = outStr + iStr[i]
	return outStr

T = int(input())
for t in range(T):
	iStr = input()
	print("Case #"+str(t+1)+":",solveIt(iStr))