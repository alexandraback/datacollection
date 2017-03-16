from sys import stdin

def calc(A, B, p):
    # press enter right away
    keys = [B+2]
    for i in range(0, A+1):
        q = 1.0
        for j in range(0,A-i):
            q = q * p[j]
        keys.append((B-A+1+2*i)*q + (B-A+1+2*i + B+1)*(1-q))
    #print keys 
    return min(keys)

T = int(stdin.readline())
for t in range(1, T+1):
    (A,B) = stdin.readline().split()
    A = int(A)
    B = int(B)
    p = stdin.readline().split()
    for i in range(0, len(p)):
        p[i] = float(p[i])
    print "Case #%d: %.6f" % (t, calc(A, B, p))
