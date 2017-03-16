import math
from math import log

f = open('input.txt')
samples = int(f.readline().strip())
output = ''
for k in range(samples):
	numCars = int(f.readline().strip())
	cars = []
	for j in range(numCars):
		v = f.readline().strip().split(" ");
		cars.append([int(v[1]),int(v[2])])


	print cars
	intersectionBlocks = []
	carsLen = len(cars)
	#first step go through and find blocking points
	blockingGroups = []
	totalTimes = []
	for c1 in range(carsLen):
		for c2 in range(c1+1, carsLen):
			if(cars[c1][0]-cars[c2][0] != 0):
				#t1 = float(cars[c2][1]-cars[c1][1]-5)/(cars[c1][0]-cars[c2][0])
				#t2 = float(cars[c2][1]-cars[c1][1]+5)/(cars[c1][0]-cars[c2][0])
				#print t1,t2
				pass
			else:
				#test if cars are intersecting otherwise ignore
				if(abs(cars[c2][1]-cars[c1][1]) < 10):
					print "cannot pass cars"
					length = abs(cars[c2][1]-cars[c1][1])+5
					blockingGroups.append([cars[c2][0],min(cars[c2][1], cars[c1][1]),length])
		
	for c1 in range(carsLen):
		intmin = []
		intmax = []
		intmid = []
		intDeltaTime = []
		for c2 in range(0,carsLen):
			if c1 == c2:
				continue
			if(cars[c1][0]-cars[c2][0] == 0):
				if (abs(cars[c2][1]-cars[c1][1]) < 5):
					intDeltaTime.append([0,9999999999, c1, c2])
					
					intmin.append(min(cars[c1][1],cars[c2][1])+cars[c1][1] )
					intmax.append(10)
					intmid.append(10)

				else:
					continue
			else:
				t1 = float(cars[c2][1]-cars[c1][1]-5)/(cars[c1][0]-cars[c2][0])
				t2 = float(cars[c2][1]-cars[c1][1]+5)/(cars[c1][0]-cars[c2][0])
				tmin = min(t1,t2)
				tmax = max(t1,t2)
				pc1min = tmin*cars[c1][0]+cars[c1][1]
				pc2min = tmin*cars[c2][0]+cars[c2][1]

				pc1max = tmin*cars[c1][0]+cars[c1][1]
				pc2max = tmin*cars[c2][0]+cars[c2][1]

				#intmin.append([pc1min,pc2min])
				#intmax.append([pc1max, pc2max])\
				intmin.append(min(pc1min,pc2min))
				intmax.append(max(pc1max, pc2max))
				intmid.append((min(pc1min,pc2min)+max(pc1max, pc2max))/2)
				
				intDeltaTime.append([tmin, tmax, c1, c2])
				
				'''if len(intmin)>2:
				intSize = len(intmin)
				for inum1 in range(intSize):
					for inum2 in range(inum1+1, intSize):
						for inum3 in range(inum2+1, intSize):
							max(max(intmin[inum1],intmin[inum2]),intmin[inum3]) > min(min(intmin[inum1],intmin[inum2]),intmin[inum3])
							print "not possible"
					#find the first intersection in min'''
		#print intDeltaTime
		times = []
		whatToWhat = []
		if(len(intDeltaTime) > 1):
			#check if one delta contains another
			numDelta = len(intDeltaTime);
			for nd1 in range(numDelta):
				for nd2 in range(nd1+1, numDelta):
					d1 = intDeltaTime[nd1]
					d2 = intDeltaTime[nd2]

					c1 = intDeltaTime[nd1][2]
					c2 = intDeltaTime[nd1][3]
					c3 = intDeltaTime[nd2][2]
					c4 = intDeltaTime[nd2][3]


					#grab the first instance where this is true
					collisionTime = -1
					if d1[0] >= d2[0] and d1[1] <= d2[1] :
						collisionTime = d1[0]
					elif d2[0] > d1[0] and d2[1] < d1[1] :
						collisionTime = d2[0]

					elif d1[0] > d2[0] and d1[1] > d2[1]:
						collisionTime = d1[0]
					elif d2[0] > d1[0] and d2[1] > d1[1]:
						collisionTime = d2[0]
					
					#test if the collision is any good
					dist = [0,0,0,0]
					dist[0] = cars[c1][0]*collisionTime+cars[c1][1]
					dist[1] = cars[c2][0]*collisionTime+cars[c2][1]
					dist[2] = cars[c3][0]*collisionTime+cars[c3][1]
					dist[3] = cars[c4][0]*collisionTime+cars[c4][1]


					if collisionTime >= 0 and max(dist)-min(dist) <= 6:
						#print collisionTime
						times.append(collisionTime);
						whatToWhat.append([nd1, nd2])
					else:
						#print "seems legit"
						pass
		
		else:
			#print "possible"
			#have a b
			pass
		count = 0;
		countneg = 0
		'''
		for ww in whatToWhat:
			#print len(intmin), ww[0], ww[1]
			if (abs(intmin[ww[0]]-intmin[ww[1]]) > 5):
				times.pop(count)
				count -=1
			elif (abs(intmax[ww[0]]-intmax[ww[1]]) > 5):
				times.pop(count)
				count -=1
			count += 1
		count = 0;
		for ww in whatToWhat:
			print carsLen
			print ww[0], ww[1] , 'werasdrf'
			count += 1
		'''
		times.sort()
		if len(times) > 0:
			print times[0]
			totalTimes.append(times[0])

		else:
			print "possible"

	

	#print blockingGroups
	if len(totalTimes) > 0:
		totalTimes.sort()
		output += 'Case #' + str(k+1)+': ' + str(totalTimes[0]) + '\n'
	else:
		output += 'Case #' + str(k+1)+': ' + str('Possible') + '\n'



o = open('output.txt', 'w')
o.write(output)
o.close
print output
