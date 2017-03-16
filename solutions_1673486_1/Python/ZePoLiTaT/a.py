from sys import stdin

num_cases = int(stdin.readline())
for case_index in xrange(1, num_cases+1):
    a,b = map(int,stdin.readline().strip().split(' '))    
    p = map(float,stdin.readline().strip().split(' '))    

##    print p
    pac=[p[0]]
    e = b + 2
    
    for i in xrange(1,a):
        pac.append( pac[i-1] * p[i] )

    for k in xrange(a):
##        print a, k, a-k
        ek = (b-a+2*k+1)*pac[a-k-1] + (2*b-a+2*k+2)*(1-pac[a-k-1])
        e = min(e,ek)


##    print pac        
    print "Case #" + str(case_index) + ": " + str(e)
