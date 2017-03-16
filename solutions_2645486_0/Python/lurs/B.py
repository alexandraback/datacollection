import sys

def sign(p):
    if p< 0:
        return -1
    elif p>0:
        return 1
    else:
        return 0

def solver(E,R,V,X):
    #X current energy.
    if R>=E:
        #print X
        return E*sum(V)
    elif R<E:
        if len(V) == 1:
            #print X
            return X*V[0]
        else:
            MAX = 0
            e = 0
            for x in xrange(X+1):
                #0 to X
                s = len(V)
                W = V[1:s]
                #print x,W,X-x+R,V[0]
                LOOP = V[0]*x + solver(E,R,W,min(E,X-x+R))
                #print LOOP
                if LOOP>MAX:
                    MAX = LOOP
                    #print e
                    e = x
            return MAX
        


if __name__ == "__main__":
    fid = sys.stdin
    if len(sys.argv) >= 2:
        fname = sys.argv[1]
        if fname != '-':
            fid = open(fname)
            output = open('output.out','w')
    t = int(fid.readline().strip())#the number for test cases
    #some settings code
    
    for _t in xrange(t):
        
        E,R,N = map(int, fid.readline().strip().split(' '))
        V = list(map(int, fid.readline().strip().split(' ')))
        curr = E
        SUM = 0
   
        out = solver(E,R,V,E)
 
            
            
        output.write("Case #%d: %d\n" % (_t+1,out))
        

fid.close()
output.close()
