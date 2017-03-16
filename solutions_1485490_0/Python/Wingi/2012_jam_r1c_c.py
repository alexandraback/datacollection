import StringIO, sys

if len(sys.argv)>1:
    input = file(sys.argv[1]).readline
else:
    input = StringIO.StringIO("""4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
1 5
3 1
1 1 1 4 1 1 1 5 1 1""").readline

def solve(a, b, s=0, iA=0, aGot=0, iB=0, bGot=0, depth=0):

    def typA(): return a[iA*2+1]
    def typB(): return b[iB*2+1]
    def cntA(): return a[iA*2]-aGot
    def cntB(): return b[iB*2]-bGot

    if iA*2==len(a) or iB*2==len(b):
        return s

    #print "(%d) 1.Summe: %d, A(%d): %dx%d, B(%d): %dx%d" % (depth,
    #      s, iA, cntA(), typA(), iB, cntB(), typB())

    if typA() == typB():
        if cntA()>cntB():
            #print "\ttake %d from a, inc.b" % (cntB())
            aGot += cntB() # remeber got from a
            s+=cntB()            # add to sum
            iB+=1                # jump to next type
            bGot=0
            if iB*2==len(b):
                #print "(%d) Summe: %d (iB:%d)" % (depth, s, iB)
                return s
        else:
            #print "\ttake %d from b, inc.a" % (cntA())
            bGot +=cntA()
            s+=cntA()
            iA+=1
            aGot = 0
            if iA*2==len(a):
                #print "(%d) Summe: %d" % (depth, s)
                return s

    #print "(%d) 2.Summe: %d, A(%d): %dx%d, B(%d): %dx%d" % (depth,
    #      s, iA, cntA(), typA(), iB, cntB(), typB())


    #throw A away
    sA = solve(a, b, s, iA+1, 0, iB, bGot, depth+1)
    sB = solve(a, b, s, iA, aGot, iB+1, 0,  depth+1)
    
    return max(sA, sB)
            


for case in range(int(input())):
    n, m = map(int, input().split())
    a = map(int, input().split())
    b = map(int, input().split())
    #print a,b
    print "Case #%d: %d" % (case+1, solve(a,b))
