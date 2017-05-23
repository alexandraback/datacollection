import itertools


def solve(C, J):
    def to_str(t):
        r=''
        for x in t:
            r += str(x)
        return r
        
    def to_nbr(t):
        r = 0
        for x in t:
            r = r*10+x
        return r
    
    res = 100000000000000000000
    
    n = len(C)
    for t1 in itertools.product(range(10), repeat=n):
        f1 = True
        for i in xrange(n):
            if C[i]!='?' and int(C[i])!=t1[i]:
                f1 = False
                break
        if f1:
            for t2 in itertools.product(range(10), repeat=n):
                f2 = True
                for j in xrange(n):
                    if J[j]!='?' and int(J[j])!=t2[j]:
                        f2=False
                        break
                if f2:
                    x1 = to_nbr(t1)
                    x2 = to_nbr(t2)
                    z = abs(x1-x2)
                    if z < res:
                        res = z
                        cbest = to_str(t1)
                        jbest = to_str(t2)                                                          
                                            
    return cbest, jbest

#filespec = "e:/work/code_jam/Close Match.txt"    
filespec = "d:/downloads/B-small-attempt0.in"
#filespec = "d:/downloads/A-large.in"
#filespec = "e:/work/code_jam/test.txt"    
f = open(filespec, 'r')
out = open("e:/work/code_jam/out.txt", 'w')

T = int(f.readline())
for nbr in range(1, T+1):
    C, J = f.readline().strip().split()
    CBest, JBest = solve(C, J)
    s = "Case #%d: %s %s\n" %(nbr, CBest, JBest)
    print s,

    out.write(s)
    
f.close()
out.close()