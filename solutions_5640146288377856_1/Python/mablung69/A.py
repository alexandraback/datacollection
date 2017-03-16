f = open('A-large.in', 'r')

T = int(f.readline().strip())

import math

for t in xrange(T):

    s=0
    [R,C,W]= [int(x) for x in f.readline().strip().split(' ')]


    if W==C:
        s=R-1+W
    elif W==1:
        s=R*C
    else:
        if R==1:
            if C%W==0:
                s=W+((C-W)/W)
            else:
                s=W+((C-W)/W)+1
            #if (C-W)/W==0:
            #    s=W+((C-W)/W)+1
            #else:
            #    s=W+((C-W)/W)
        else:            
            s=((C/W)*(R-1))
            if C%W==0:
                s+=W+((C-W)/W)
            else:
                s+=W+((C-W)/W)+1

    print 'Case #%d: %d'% (t+1,s)
    

