from math import *
#prob=(open('A.in','r')).read().split()
prob=(open('A-large.in','r')).read().split()
out=''


N=int(prob[0])


def  num_rings(r,t):
    
   
    return int(floor((sqrt(8*t+ 4*r**2 - 4*r + 1)-2*r+1)/4))

    

for n in range(N):
    ro=int(prob[2*n+1])
    to=int(prob[2*n+2])
    #import pdb; pdb.set_trace()
    
    out=out + 'Case #%d: '%(n+1) + str(num_rings(ro,to))  + '\n'

    
#print out

f=open('output','w')
f.write(out)
f.close()


