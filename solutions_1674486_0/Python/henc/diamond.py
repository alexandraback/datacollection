#!/usr/bin/python
#
# stjepan.henc@fer.hr
#

T = int(input())

for k in range(T):
	graf = [[],]

	ulaz = input()
	N = int(ulaz)
	
	for i in range(N):
		ulaz = input()
		ulaz = ulaz.split(' ')
		
		graf.append([int(x) for x in ulaz[1:len(ulaz)]])
		
	pocetak = []
	
	#print("N", N)
	#print("graf", graf)
	
	pomocni = [0] * (N + 1)
	
	for g in graf:
		for i in g:
			pomocni[i] = 1
	
	for i in range(1, N + 1):
		if pomocni[i] == 0:
			pocetak.append(i)
	
	ret = 0
	
	#print("poc", pocetak)
	
	for l in pocetak:
		pomocni = [0] * (N + 1)
		zovi = [l]
		novi_zovi = []
		
		q = 1
		while (q != 0):
		#	print("zov", zovi)
			
			q = 0
			for z in zovi:
		#		print(z, N)
				pomocni[z] += 1
				q = 1
		#		print("gr", graf[z])
				for b in graf[z]:
					novi_zovi.append(b)
					
			zovi = [x for x in novi_zovi]
			novi_zovi = []
			
		#print("pom", pomocni)
		
		for i in pomocni:
			if i > 1:
				ret = 1
				break
				
		if ret == 1:
			break
	
	if ret == 1:
		sol = "Yes"
	else:
		sol = "No"

	print("Case #" + str(k + 1) + ":", sol)	

