def checkCircle(N,BFFs,circle):
	if len(circle) <= 1:
		return True
	for i in range(len(circle)):
		IDcour = circle[i]
		iright = i+1
		ileft = i - 1
		if iright >= len(circle):
		 	iright = 0
		if ileft < 0:
		 	ileft = -1
		IDsNext = [circle[iright], circle[ileft]]
		#print(circle, IDcour, IDsNext)
		if BFFs[IDcour] in IDsNext:
			continue
		else:
			#print(circle, IDcour, IDsNext)
			return False
	return True

def checkCircleInside(N,BFFs,circle):
	for i in range(1,len(circle)-1):
		IDcour = circle[i]
		iright = i+1
		ileft = i - 1
		if iright >= len(circle):
		 	iright = 0
		if ileft < 0:
		 	ileft = -1
		IDsNext = [circle[iright], circle[ileft]]
		#print(circle, IDcour, IDsNext)
		if BFFs[IDcour] in IDsNext:
			continue
		else:
			#print(circle, IDcour, IDsNext)
			return False
	return True

def rec(N,BFFs, circle):
	IDnotIn = [i for i in range(1,N+1) if i not in circle]
	#print(IDnotIn,circle)
	#print(circle)
	sizeMax = -1
	circleOK = checkCircleInside(N,BFFs,circle)
	if not circleOK:
		return -1
	for e in IDnotIn:
		cercleBis = circle
		cercleBis = cercleBis + [e]
		if checkCircle(N,BFFs, cercleBis):
			sizeMax = max(sizeMax,len(cercleBis))
		sizeMax = max(sizeMax,rec(N,BFFs,cercleBis))

	return sizeMax

T = int(input())
for t in range(T):
	N = int(input())
	BFFs = list(map(int,input().split()))
	BFFs = [0] + BFFs
	circleRes = list()

	sizeCircleRes = rec(N,BFFs,circleRes)

	print("Case #{}: {}".format(t+1,sizeCircleRes))
