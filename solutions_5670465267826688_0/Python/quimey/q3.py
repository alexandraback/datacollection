m = {
    ('1','1'):(1,'1'),
    ('1','i'):(1,'i'),
    ('1','j'):(1,'j'),
    ('1','k'):(1,'k'),
    ('i','1'):(1,'i'),
    ('i','i'):(-1,'1'),
    ('i','j'):(1,'k'),
    ('i','k'):(-1,'j'),
    ('j','1'):(1,'j'),
    ('j','i'):(-1,'k'),
    ('j','j'):(-1,'1'),
    ('j','k'):(1,'i'),
    ('k','1'):(1,'k'),
    ('k','i'):(1,'j'),
    ('k','j'):(-1,'i'),
    ('k','k'):(-1,'1'),
}
    
def p((a,b), (c,d)):
    (e,f) = m[(b,d)]
    return (a*c*e,f)

T = input()

for tt in range(T):
    L, X = map(int, raw_input().split())
    S = raw_input()
    if X>12:
        X = 12 + (X % 12)
    S *= X
    r = (1, '1')
    t = (1, 'i')
    for s in S:
        r = p(r,(1,s))
        if r == t:
            if t== (1,'i'):
                r = (1, '1')
                t = (1, 'j')
            elif t== (1,'j'):
                r = (1, '1')
                t = (1, 'k')
    if r == t:
        print "Case #%d: YES" % (tt+1)
    else:
        print "Case #%d: NO" % (tt+1)
