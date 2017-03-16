inputfile = file("a-small.in", "rb")
outputfile = file("a-small.out", "wb")
out_yes = "Case #%d: %s"

def gcd(a,b):
    if b==0: return a
    if b>a: return gcd(b,a)
    return gcd(b, a%b)

parse_line = lambda: [int(a) for a in inputfile.readline().split()]

def log2(x):
    if x==0:
        raise Exception("Baah")
    n = -1
    while x:
        n += 1
        x >>= 1
    return n

T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    P, Q = [int(a) for a in inputfile.readline().split('/')]
    g = gcd(P, Q)
    P, Q = P/g, Q/g
    if (Q & (Q-1)) != 0:
        print >>outputfile, out_yes % (ncase, 'impossible')
        continue
        
    if P == 1:
        print >>outputfile, out_yes % (ncase, str(log2(Q)))
        continue
        
    P = 1 << (log2(P) + 1)
    g = gcd(P, Q)
    P,Q = P/g, Q/g
    print >>outputfile, out_yes % (ncase, str(log2(Q)+1))
    