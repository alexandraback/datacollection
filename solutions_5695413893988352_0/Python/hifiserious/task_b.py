t = int(raw_input())  
for i in xrange(1, t + 1):
	sc1, sc2 = raw_input().split(" ")

	sc1 = list(sc1)
	sc2 = list(sc2)
	sc1Lower = False
	sc2Lower = False
	for x in xrange(len(sc1)):
		if sc1[x] == '?':
			if sc2[x] == '?':
				if x - 1 >= 0:
					if sc1[x-1] > sc2[x-1]:
						sc1[x] = 0
						sc2[x] = 9
						sc2Lower = True

					elif sc1[x-1] < sc2[x-1]:
						sc2[x] = 0					
						sc1[x] = 9
						sc1Lower = True
					else:
						sc2[x] = 0					
						sc1[x] = 0
				else:
					sc1[x] = 0
					sc2[x] = 0
			else:
				if x - 1 >= 0:
					if (sc1[x-1] > sc2[x-1] and not sc1Lower and not sc2Lower) or sc2Lower:
						sc1[x] = 0
						sc2Lower = True

					elif (sc1[x-1] < sc2[x-1] and not sc1Lower and not sc2Lower) or sc1Lower:
						sc1[x] = 9
						sc1Lower = True
					else:
						sc1[x] = sc2[x]
				else:
					if x + 1 < len(sc1):
						if sc2[x+1] != '?' and int(sc2[x+1]) <= 5:
							sc1[x] = max(int(sc2[x]) - 1, 0)
						else:
							sc1[x] = sc2[x] 
					else:	
						sc1[x] = sc2[x] 
		elif sc2[x] == '?':
			if x - 1 >= 0:
					if (sc1[x-1] > sc2[x-1] and not sc1Lower and not sc2Lower) or sc2Lower:
						sc2[x] = 9
						sc2Lower = True

					elif (sc1[x-1] < sc2[x-1] and not sc1Lower and not sc2Lower) or sc1Lower:
						sc2[x] = 0
						sc1Lower = True
					else:
						sc2[x] = sc1[x]
			else:
				if x + 1 < len(sc1):
					if sc1[x+1] != '?' and int(sc1[x+1]) <= 5:
						sc2[x] = max(int(sc1[x]) - 1, 0)
					else:
						sc2[x] = sc1[x] 
				else:	
					sc2[x] = sc1[x] 


	sc1 = ''.join(str(x) for x in sc1)
	sc2 = ''.join(str(x) for x in sc2)


	print "Case #{}: {} {}".format(i, sc1, sc2)