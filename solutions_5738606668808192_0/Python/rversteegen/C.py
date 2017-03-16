## jam coin
T = int(raw_input())
for testcase in range(T):
    N,J = [int(x) for x in raw_input().split()]
    print "Case #%d:" % (testcase + 1)
    for coin in xrange(2**(N-1)+1, 2**N, 2):
        coinstr = bin(coin)[2:]  # strip 0b prefix
        divis = []
        for base in range(2,10+1):
            basecoin = int(coinstr, base)
            for factor in range(3, 103, 2):
                if basecoin % factor == 0:
                    divis.append(str(factor))
                    break  # composite
            else:
                break  # might be prime
        else:  # composite
            print coinstr, ' '.join(divis)
            J -= 1
            if J == 0: break
        
