def invert(N):
    return int(str(N)[::-1])

def counter(N):
    P = [ N ]*N
    P[0] = 1
    for i in range(N-1):
        cost = P[i] + 1
        value = i+1
        P[ value ] = min(P[value], cost)
        j = invert( value )
        if j > value and j <= N:
            P[j-1] = min(P[j-1], cost)
    return P[-1]

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    print "Case #%d: %d"%(i+1,counter(N))
