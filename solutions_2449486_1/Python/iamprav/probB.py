import os , sys

file = open(sys.argv[1],'r')

testnum = int(file.readline())

for test in range(1,testnum+1):
        (n , m) = [int(x) for x in file.readline().strip().split(' ') ]
        lawn = [[int(x) for x in list(file.readline().strip().split(' '))] for x in xrange(n)] 
	
	res = [[100 for x in xrange(m)] for y in xrange(n)]
	



	#row wise
	for i in xrange(n):
		max = -1
		for j in xrange(m):
			if(lawn[i][j] > max):
				max = lawn[i][j]

		for j in xrange(m):
			if(res[i][j] > max):
				res[i][j] = max

	#column wise
	for i in xrange(m):
		max = -1
		for j in xrange(n):
			if(lawn[j][i] > max):
				max = lawn[j][i]
		
		for j in xrange(n):
			if(res[j][i] > max):
				res[j][i] = max
			

        isLawn =  True;
	for i in xrange(n):
		for j in xrange(m):
			if(res[i][j] != lawn[i][j]):
				isLawn = False
				


	if isLawn:
		print "Case #%d: YES"%(test)
	else:
		print "Case #%d: NO"%(test)
			
	

	#check column wise
        
     #contruct board
     #    board  = 

    


