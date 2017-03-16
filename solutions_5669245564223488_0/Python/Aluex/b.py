import sys, numpy, math#, gmpy
#s = sys.stdin.read().split('\n')
s = open(sys.argv[1],"r").read().split('\n')
N = int(s[0])
MOD = 1000000007
BASE = ord('a')
chars = "abcdefghijklmnopqrstuvwxyz"
def inmiddle(tr, x):
	return x in tr and (x!=tr[0] and x!=tr[-1])
for delta in range(0,N):
	n = int(s[2*delta+1])
	trains = s[2*delta+2].split(' ')
	#newTrainList = []
	selfList = [0 for x in range(26)]
	startList = [0 for x in range(26)]
	endList = [0 for x in range(26)]
	res = 1
	#print trains
	tempTrains = []
	for tr in trains:
		if tr[0]==tr[-1]:
			for char in chars:
				if char != tr[0] and char in tr:
					res = 0
			selfList[ord(tr[0])-BASE] += 1
		else:
			startList[ord(tr[0])-BASE] += 1
			endList[ord(tr[-1])-BASE] += 1
			tempTrains.append(tr)
	trains = tempTrains
	#print startList
	#print endList
	#print selfList
	#print trains
	for x in range(26):
		if selfList[x] != 0 or startList[x] != 0 or endList[x] != 0:
			for tr in trains:
				if inmiddle(tr,chr(x+BASE)):
					res = 0
					break
		if startList[x] > 1 or endList[x] > 1:
			res = 0
			break
	for tr1 in trains:
		for tr2 in trains:
			if tr1[0]==tr2[-1] and tr1[-1]==tr2[0]:
				res=0
				break
	trains = [(x,1) for x in trains]
	flag = True
	while flag:
		flag = False
		ind1 = None
		ind2 = None
		for x in range(len(trains)-1):
			for y in range(x+1,len(trains)):
						if trains[x][0][-1]==trains[y][0][0]:
							ind1 = trains[x]
							ind2 = trains[y]
							#tempTrains[-1] = trains[x] + trains[y]
							flag = True
							break
						if trains[y][0][-1]==trains[x][0][0]:
							ind1 = trains[y]
							ind2 = trains[x]
							#tempTrains[-1] = trains[x] + trains[y]
							flag = True
							break
			if flag:
				break
		if flag:
			trains.append((ind1[0]+ind2[0],ind1[1]+ind2[1]))
			trains.remove(ind1)
			trains.remove(ind2)
		#print trains
	
	length = len(trains)
	for tr, freq in trains:
		if tr[0]==tr[-1]:
			res=0
			break
		for tr2, freq2 in trains:
			if tr[0] == tr2[-1] and tr[-1] == tr2[0]:
				res=0
				break
	
	for x in range(26):
		if selfList[x]!=0 and startList[x]==0 and endList[x]==0:
			length+=1
		res *= math.factorial(selfList[x]) % MOD
	res *= math.factorial(length) % MOD
	#for it in range(n-1):
	#	res = res * matrix

	print "Case #%d: %d" % (delta+1, res)
	