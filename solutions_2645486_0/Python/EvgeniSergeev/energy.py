

import sys
si = sys.stdin

T = int(si.readline())
for icase in range(T):
    E, R, N = map(int, si.readline().split())
    vs = map(int, si.readline().split())




    have_at = [[-1] * (N+1) for i in range(E+1)]
    #print have_at
    for en in range(E+1):
        have_at[en][N] = 0
    for i in reversed(range(0, N)):
        for have in range(E+1):
            for en_use in range(0, have+1):
                add = en_use*vs[i]
                have_next = min(E, have - en_use + R)
                have_at[have][i] = max(have_at[have][i], 
                                       add + have_at[have_next][i+1])

    #for en in range(E+1):
    #    for i in range(N+1):
    #        print have_at[en][i],
    #    print ""

    print "Case #%d:" % (icase+1), have_at[E][0]
            
