import sys
def memoize(f):
    """ Memoization decorator for functions taking one or more arguments. """
    class memodict(dict):
        def __init__(self, f):
            self.f = f
        def __call__(self, *args):
            return self[args]
        def __missing__(self, key):
            ret = self[key] = self.f(*key)
            return ret
    return memodict(f)

def plus1(n):
    return str(int(n)+1) if n!='9' else '9'
def minus1(n):
    return str(int(n)-1) if n!='0' else '0'
def scorer((j,c)): 
    return (
        abs(int(j)-int(c)),
        int(c),
        int(j)
    )
@memoize
def f(C,J):
    a,b = g(C,J)
    return b,a
def g(C,J):
    if C== '':
        return ('','')
    # print >>sys.stderr, C,J
    b,a = f(C[1:],J[1:])
    
    if C[0] == '?' and J[0] == '?':
        v1 = '0'+J[1:].replace('?','9'), '1'+C[1:].replace('?','0')
        v2 = '0'+a,'0'+b
        v3 = '1'+J[1:].replace('?','0'), '0'+C[1:].replace('?','9')
        
        return min((v1,v2,v3),key=scorer)

    elif C[0] == '?':
        v1 = J.replace('?','9'), plus1(J[0])+C[1:].replace('?','0')
        v2 = J[0]+a,J[0]+b
        v3 = J.replace('?','0'), minus1(J[0])+C[1:].replace('?','9')
        
        return min((v1,v2,v3),key=scorer)
        
    elif J[0] == '?':
        v1 = plus1(C[0])+J[1:].replace('?','0'),C.replace('?','9')
        v2 = C[0]+a,C[0]+b
        v3 = minus1(C[0])+J[1:].replace('?','9'),C.replace('?','0')
        
        return min((v1,v2,v3),key=scorer)
        
    else:
        if J[0]==C[0]:
            return (J[0]+a,C[0]+b)
        elif J[0] > C[0]:
            return J.replace('?','0'),C.replace('?','9')
        else:
            return J.replace('?','9'),C.replace('?','0')
            
    # print o
    
        
        
T = int(raw_input())
for i in xrange(1,T+1):
    print "Case #%d: %s" % (i, " ".join(f(*(raw_input().split()))))
    
# 4
# OZONETOWER
# WEIGHFOXTOURIST
# OURNEONFOE
# ETHER
    


    