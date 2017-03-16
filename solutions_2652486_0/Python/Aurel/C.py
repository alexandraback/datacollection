raw_input() # number of test cases = 1
print "Case #1:"

R, N, M, K = map(int, raw_input().split())

data = []
for i in xrange(R):
    v = map(int, raw_input().split())

    for v1 in range(2, 6):
        for v2 in range(2, 6):
            for v3 in range(2, 6):
                possible = True
                for k in range(K):
                    if v1*v2*v3 != v[k] and v1*v2 != v[k] and v1*v3 != v[k] and v1 != v[k] and 1 != v[k] and v2*v3 != v[k] and v2 != v[k] and v3 != v[k]:
                        possible = False
                        break
                if possible:
                    print "{:d}{:d}{:d}".format(v1, v2, v3)
                    break
            if possible:
                break
        if possible:
             break
                
