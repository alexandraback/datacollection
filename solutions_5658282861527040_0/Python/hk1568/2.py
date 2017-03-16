import sys 




f = open(sys.argv[1])
cases = int( f.readline().strip()  )

for case in range(1, cases+1):
    
    A, B, K = map(int , f.readline().strip().split() )
    
    #print A, B, K
    c=0 
    for i in range(A):
        for j in range(B):
            #print i, j,  i ^ j
            if i & j < K:
                c+=1

            

    print "Case #%d: %d" % ( case, c ) 
