import sys

T = 0
index = 1
for line in sys.stdin:
    if T == 0:
    	T = line
    else:
    	spl = line.split(' ', 1)
    	smax = spl[0].strip()
    	s = spl[1].strip()
    	stands = 0
    	friends = 0
    	
    	for i in range(len(s)):
    		si = int(s[i])
    		
    		f = 0
    		if i > 0 and stands+friends<i and si>0:
    			friends += (i-(stands+friends))
    		
    		
    		stands += si
    	
    	print "Case #"+ str(index) + ": "+str(friends)
    	index+=1
    