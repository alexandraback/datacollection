
def lower2power(n):
    rv = 0
    while 2 ** (rv + 1) <= n:
        rv += 1
    return rv 

def process_game():
    P, Q = map(int, raw_input().split("/"))
    if (Q - 1) & Q != 0:
        print "impossible"
        return
    last = lower2power(Q)
    while P != 0:
        assert(Q != 0)
        assert(P % 2 == 1)
        last = lower2power(Q)
        P -= 1
        while P != 0 and P % 2 == 0:
            P /= 2
            Q /= 2
    print last
                        
for i in xrange(1, int(raw_input()) + 1):
    print "Case #%d:" % (i),
    process_game()
