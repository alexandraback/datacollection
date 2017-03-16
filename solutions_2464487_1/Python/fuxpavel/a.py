from numpy import sqrt
import decimal
decimal.getcontext().prec = 100

def find_roots(a,b,c):
    a = decimal.Decimal(a)
    b = decimal.Decimal(b)
    c = decimal.Decimal(c)
    return ((-b/(2*a))+(decimal.Decimal((b*b-4*a*c)/(4*a*a)).sqrt()),(((-b/(2*a))-decimal.Decimal((b*b-4*a*c)/(4*a*a)).sqrt())))

def get_n(a1,sn):
    return find_roots(2,(a1-2),-sn)

def get_rings_num(r,t):
    return int(max(get_n(2*r+1, t)))

def main(args):
    inf = open(args[1])
    outf = open(args[2], 'wt')
    for i in xrange(1,int(inf.readline())+1):
        r,t = (int(j) for j in inf.readline().split())
        outf.write("Case #%d: %d\n" % (i, get_rings_num(r,t)))
    
    
if __name__ == "__main__":
    import sys
    main(sys.argv)
