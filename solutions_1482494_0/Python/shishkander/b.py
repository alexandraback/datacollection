#!/usr/bin/env python


def case(N, A, B):
    _B = B
    _A = A
    A = [(A[i], i) for i in xrange(N)]
    B = [(B[i], i) for i in xrange(N)]

    B.sort()
    def cmp2(el1,el2):
        v1, i1 = el1
        v2, i2 = el2
        if v2 != v1:
            return cmp(v1, v2)
        return -cmp( _B[i1], _B[i2] )
    A.sort()
    print "A1:", A
    A.sort(cmp=cmp2)
    print "B:", B
    print "A2:", A

    
    A.append( (None, None) )
    B.append( (None, None) )

    stars = 0
    PA = set()
    PB = set()
    a, b = 0, 0 
    changed = True
    while changed:
        changed = False
        while b<N and B[b][0] <= stars:
            if B[b][1] in PA:
                stars += 1
            else:
                stars += 2
            PB.add( B[b][1] )
            #print "added PB %i" % (B[b][1])
            b += 1
            changed = True

        if b == N:
            assert stars == N*2
            assert len(PA) <= a
            return len(PA) + N
        else:
            assert stars < N*2
            assert len(PA) <= a
            assert stars == len(PB)*2 + len( set(list(PA)).difference(PB) )

        while a<N and A[a][0] <= stars:
            if not A[a][1] in PB:
                stars += 1
                changed = True
                PA.add( A[a][1] )
                #print "added PA %i" % (A[a][1])
                a += 1
                break
            else:
                a += 1

        print changed, stars, sorted(PA), sorted(PB)
        print "\t", a, A[a:-1]
        print "\t", b, B[b:-1]
    return "Too Bad"



def solve(fin, fout):
    T = int(fin.readline())
    for t in xrange(T):
        N = int( fin.readline().strip() )
        A = [0] * N
        B = A[:]
        for i in xrange(N):
            A[i], B[i] = map(int, fin.readline().strip().split(' '))
        fout.write("Case #%i: %s\n" % (t+1, case(N,A,B)) )
    return True

if __name__ == "__main__":
    import sys
    with open(sys.argv[1],'r') as fin:
        with open(sys.argv[2], 'w') as fout:
            solve(fin, fout)
