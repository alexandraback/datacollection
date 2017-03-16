import sys

file = sys.argv[1]

lines = open(file).readlines()
T = int(lines[0])

currentLine = 1

for case in range(T):
	N,M,K = map(int,lines[currentLine].split())
	currentLine = currentLine + 1
	#print "{} {} {}".format(N,M, K)
	#Square is most optimal
	X = 0
	Y = 0
	if N < M:
		temp = M
		M = N
		N = temp		
	if M == 1:
		if N == 1:
			print "Case #{}: {}".format(case + 1 ,K )
			continue
		stones = (K + 1)/ 2
		#if odd and all of them, bonus
		if N == K and N % 2 == 1:
			stones -=1
		print "Case #{}: {}".format(case + 1 ,stones )	
		continue
		
	if M == 2:
		if K == M * N:
			print "Case #{}: {}".format(case + 1 ,K/2 )
			continue
		print "Case #{}: {}".format(case + 1 ,(K +1)/2 )
		continue
	if M == 3:
		row = 1
		stones = 1
		total = 1
		while True:
			if row == N:
				print "Case #{}: {}".format(case + 1 ,stones )
				break
			if total >= K:
				print "Case #{}: {}".format(case + 1 ,stones )
				break
			stones += 1
			total += 2
			if total >= K:
				print "Case #{}: {}".format(case + 1 ,stones )
				break
			row +=1
			stones += 1
			total += 2				
			if row == N:
				print "Case #{}: {}".format(case + 1 ,stones )
				break

			if total >= K:
				print "Case #{}: {}".format(case + 1 ,stones )
				break
			row +=1
			stones += 1
			total += 2
	else:			
		total = 0
		while True:
			#print "{} {}".format(N,M)
			#print "{} {} {} {}".format(X, Y ,total,  K)
			bonus = 0
			if X == N - 2 and Y == M - 2:
				bonus = 4
			elif X == N - 2 and Y > 0:
				bonus = 2
			elif Y == M - 2 and X > 0:
				bonus = 2			
			
			total = X * Y + 2 * X + 2 * Y + bonus
			if total > K - Y - 2:
				if total > K - X - 2:
					stones = 2 * X + 2 * Y + K - total			
					#print "Keith1 {} {} {} {}".format(X,Y,K,K - total) 
					break;
			elif X < N - 2:
				X += 1	
			else:
				if Y >= M - 2:
					stones = 2 * X + 2 * Y + K - total
					#print "Massive {} {} {} {}".format(X,Y,K,K - total) 
					break;	
				
				
			bonus = 0
			if X == N - 2 and Y == M - 2:
				bonus = 4
			elif X == N - 2 and Y > 0:
				bonus = 2
			elif Y == M - 2 and X > 0:
				bonus = 2			

			total = X * Y + 2 * X + 2 * Y + bonus
			if total > K - X - 2:
				if total > K - Y - 2:
					stones = 2 * X + 2 * Y + K - total
					#print "Keith2 {} {} {} {}".format(X,Y,K,K - total) 
					break;
			elif Y < M - 2:
				Y += 1	
		if M == 3 and X == 1 and Y > 1:
			stones -= (Y-1)/2
				

		print "Case #{}: {}".format(case + 1 ,stones )