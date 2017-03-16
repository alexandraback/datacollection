import time

s_time=time.time()

def rings(r,t):
	total=0
	current_r=r
	result=0

	while True:
		total += 1+2*current_r
		current_r +=2
		if total> t:
			break
		result+=1
	return result






f= open('A-small-attempt0.in','r')
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







