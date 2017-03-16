from sys import stdin
rl = stdin.readline

T = int(rl())

def check(n, a):
    if n == 0:
        return True
    if a == 41:
        return False
    
    n *= 2
    if n == 1:
        return True
    if n > 1:
        n -= 1
    else:
        n = n

    return check(n, a+1) 


for t in xrange(1, T+1):
    P, Q = map(float, rl().split('/'))
    A = 0
    result = '' 
    pq = P/Q
    for i in xrange(41):
        A += 1
        pq *=  2
        #if pq == 1.0 or pq == 1.5 or pq == 2.0:
        if pq >= 1 and pq <= 2:
            break

    if A == 41 or check(pq-1, A) is False:
        print 'Case #%d: impossible' % t
    else:
        print 'Case #%d: %d' % (t, A)             
