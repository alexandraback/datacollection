import numpy as np

def fractiles():
    f = open('input4', 'r')
    dat = f.read()
    data_in = dat.split()
    n = int(data_in[0])
    a = np.array(data_in[1:],dtype=int).reshape((n,3))
    #print a
    for i in xrange(n):
        k = a[i][0]
        c = a[i][1]
        s = a[i][2]
        if(c==1):
            if(k!=s):
                print 'Case #%d: IMPOSSIBLE' %(i+1)
            else:
                print 'Case #%d:' %(i+1),
                for j in range(1,s+1):
                    print j,
                print
        else:
            if(k==s):
                print 'Case #%d:' %(i+1),
                for j in xrange(1,k+1): 
                    print j,
                print 
            #elif(s<np.ceil(k/2.0)):
                #print 'Case #%d: IMPOSSIBLE' %(i+1)
            #else:
                #kc = k**(c-1)
                #print 'Case #%d:' %(i+1),
                #if(k%2 ==0):
                    #for j in xrange(0,k/2,1):
                        #print 2*j*kc+2*(j+1),
                    #print
                #else:

                    #for j in xrange(0,k/2,1):
                       # print 2*j*kc+2*(j+1)
                    #print (j+2)*kc+2*(j+1)+1 
fractiles()
