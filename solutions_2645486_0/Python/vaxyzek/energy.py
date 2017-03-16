import sys, math


def fill(S, E, R, N, v):
    for n in range(N - 1, -1, -1):
        for e in range(E + 1):
            #print "e=",e
            m = 0
            for i in range(e + 1):
                ne = min(E, e - i  + R)
                s = int(v[n]) * i + S[n + 1][ne]
                m = max(s, m)
            #print "m=",m
            S[n][e] = m
        #print S


f = open(sys.argv[1])
T = int(f.readline())

for i in range(T):
    (E, R, N) = f.readline().split()
    N = int(N)
    E = int(E)
    R = int(R)
    v = f.readline().split()

    S = [[0] * (E + 1) for n in range(N + 1)]

    #print S

    fill(S, E, R, N, v)
        
    print "Case #" + str(i+1) + ": " + str(S[0][E])
    #print 