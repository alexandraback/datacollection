import sys
p='abcdefghijklmnopqrstuvwxyz '
c='yhesocvxduiglbkrztnwjpfmaq '
d=dict(zip(p,c))

def test(G):
    return ''.join(map(lambda x:d[x], G))
        
    
    

T = int(raw_input())
for t in xrange(T):
    G = raw_input()
    print >>sys.stderr, t
    print "Case #%d:" % (t+1), test(G)
