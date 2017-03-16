import time
import math
s_time=time.time()

def rings(r,t):
	result=int(math.sqrt(t/2))-r/2
	if result<0:
		result=0

	while True:
		if result*(result*2+2*r-1)>t:
			break
		result+=1

	return result-1






f= open('A-large.in','r')
q= open('result.txt','w')

count=1
f.readline()

for line in f:
    r,t=[int(x) for x in line[:-1].split(' ')]
    
    #print rings(r,t)
    s='Case #'+str(count)+': '+str(rings(r,t))+'\n'  
    count +=1  
    q.write(s)
    print 'ok'+str(count-1)
        
                
f.close()
q.close()
print 'seconds:',time.time()-s_time







