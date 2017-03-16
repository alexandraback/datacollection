from itertools import permutations
T = int(raw_input())
for i in xrange(T):
    N = int(raw_input())
    b = [int(x)-1 for x in raw_input().split()]
    solved = False
    for L in xrange(N, 0, -1):
        for x in permutations(range(N), L):
            if x[0] != min(x):
                continue
            x = (x[-1],) + x + (x[0],)
            #print x
            for j in xrange(1, L+1):
                if b[x[j]] != x[j-1] and b[x[j]] != x[j+1]:
                    break
                if j == L:
                    solved = True
            if solved:
                #print "Viable: ", x
                break
        if solved:
            break
    
    print "Case #%d: %d" % (i+1, L)