import math
f=open('/Users/pruthvikarreddy/Downloads/C-small-attempt1.in').read()
o = open('/Users/pruthvikarreddy/Downloads/outcs1.txt','w')
v=f.splitlines()

for ix,x in enumerate(f.splitlines()[1:]):
    R,C,M=[int(n) for n in x.split(' ')]
    
    poss=False
    #  one space        there is a box              is clean
    if M==R*C-1 or (M<=R*C-R*2 and M%R==0) or (M<=R*C-C*2 and M%C==0):
        o.write('Case #'+str(ix+1)+':'+'\n')
        poss=True  
    #                   
    else:
        o.write('Case #'+str(ix+1)+':'+'\n')
        o.write('Impossible'+'\n')
    #    

    

    if poss:
        l=['.' for t in range(C)]
        g=[]
        for i in range(R):
           g.append(l[:])
        g[-1][-1]='c' 
        if M%C==0:
            while M>0:
                for i in xrange(R):
                    for j in xrange(C):
 
                        if g[i][j]!='*':
                            if M==0:
                                break
                            g[i][j]='*'
                            M-=1
        else:
            while M>0:
                for i in xrange(C):
                    for j in xrange(R):
 
                        if g[j][i]!='*':
                            if M==0:
                                break
                            g[j][i]='*'
                            M-=1

        for i,l1 in enumerate(g):
            g[i]=''.join(l1)
        o.write('\n'.join(g)+'\n')

