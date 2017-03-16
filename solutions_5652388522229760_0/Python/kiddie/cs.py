import numpy as np

def countsheep():
    a = np.loadtxt('input',dtype=int)
    a = a[1:]
    #print a
    for i,n in enumerate(a):
        discovered = set()
        #print discovered
        if n == 0:
            print 'Case #%d: INSOMNIA' %(i+1)
        else:
            N = 1
            while(1):
                
                numb = str(n*N)
                discovered.update(list(numb))
                #print discovered
                if(len(discovered) == 10):
                    #print n
                    #print discovered
                    print 'Case #%d: %d' %(i+1, n*N)
                    break
                N = N+1
countsheep()



