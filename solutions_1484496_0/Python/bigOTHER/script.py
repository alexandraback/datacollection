#!/bin/python


# read the input
f=open("in")
T=int(f.readline())


output=""
for i in xrange(T):
    raw_list=map(lambda x:int(x),f.readline()[:-1].split())
    N,a=raw_list[0],raw_list[1:]
    deja_vu={}
    for x in range(1,2**N):
	b=[];cpt=0;y=x
	while(x):
		#print x,
		if x%2:
			b.append(a[cpt])
		else:
			pass
		x/=2
		cpt+=1
	somme=sum(b)	
	#print y,somme,b
	if deja_vu.has_key(somme):
		print "deja vu"
		xt=deja_vu[somme].pop()
	      	bt=[];cptt=0;
		while(xt):
		    if xt%2:
			    bt.append(a[cptt])
		    else:
			    pass
		    xt/=2
		    cptt+=1
		
		print b,"=",bt,"=",somme
		
		break;
		"""
		if y in deja_vu[somme]:
		    print "deja vu"
		    break;
		else:
		    deja_vu[somme].append(y)
		    
		"""
	else:
	    deja_vu[somme]=[y]
	
    output+="Case #%d:\n%s\n%s\n" % (i+1," ".join(map(lambda x:str(x),b))," ".join(map(lambda x:str(x),bt)))
    print output
    
    
    
    
    
OUTPUT=open("out","w")
OUTPUT.write(output)
print output
print "done"
    
    
    