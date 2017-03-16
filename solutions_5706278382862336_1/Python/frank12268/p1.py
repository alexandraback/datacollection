import sys

def gcd(a,b):
    x = min(a,b)
    y = max(a,b)
    while x!=0:
        z = y%x
        y = x
        x = z
    return y

def main(ifn='ain.txt',ofn='aout.txt'):
    sys.setrecursionlimit(2000)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                p0,q0 = map(int,inf.readline().strip().split('/'))
                t = gcd(p0,q0)
                p = p0/t
                q = q0/t
                print p0,q0,"     ",p,q
                bits = 0
                half = 0
                while q!=1:
                    bits += 1
                    if p+p>=q:
                        half = bits
                        p = 0
                    if q%2!=0:
                        bits = -1
                        break
                    else:
                        q /= 2
                if bits==-1:
                    answer = 'impossible'
                else:
                    answer = '%d' %(half)
                ouf.write("%s\n" %(answer))
                print "%s" %(answer)

