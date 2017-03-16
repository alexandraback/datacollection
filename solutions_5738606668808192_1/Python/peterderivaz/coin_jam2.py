def small_factor(x,limit):
    for d in range(2,min(x,limit)):
        if x%d==0:
            return d
    return 0

for t in range(input()):
    N,J=map(int,raw_input().split())

    print "Case #{}:".format(1+t)
    n=2**(N-1)+1
    while J:
        A = []
        for base in range(2,11):
            b = bin(n)[2:]
            x = int(b,base)
            f = small_factor(x,100)
            if f:
                A.append(str(f))
            else:
                break    
        else:
            print b,' '.join(A)
            J -= 1
        n += 2
    
