from operator import mul

def nCk(n,k):
    return int(round(reduce(mul, (float(n-i)/(i+1) for i in range(k)), 1)))


with open('input.in') as fi:

    outfile = open('output.out','w')
    
    cases = int(fi.readline())
    print cases
    for case in range(1,cases+1):
        n,x,y = [int(aa) for aa in fi.readline().split()]
        x = abs(x)

        s = x+y
        small = nCk(s,2)
        r = n - small

        print small
        print r
        print y
        
        if r <= 0:
            print "CASO 1"
            print "Case #%d: %f" % (case,float(0))
            outfile.write("Case #%d: %f\n" % (case,float(0)))
            continue
        elif x==0:
            if r >= 2 * y + 1:
                print "CASO 2"
                print "Case #%d: %f" % (case,float(1))
                outfile.write("Case #%d: %f\n" % (case,float(1)))
                continue
            else:
                print "CASO 3"
                print "Case #%d: %f" % (case,float(0))
                outfile.write("Case #%d: %f\n" % (case,float(0)))
                continue
        elif r >= s + y +1:
            print "CASO 4"
            print "Case #%d: %f" % (case,float(1))
            outfile.write("Case #%d: %f\n" % (case,float(1)))
            continue
            
        
        
        q = float(0)
        for k in range(y+1):
            q += float(nCk(r,k))
        q = q / float(2**r)
        p = 1 - q
        
        print "Case #%d: %f" % (case,p)
        outfile.write("Case #%d: %f\n" % (case,p))
        
