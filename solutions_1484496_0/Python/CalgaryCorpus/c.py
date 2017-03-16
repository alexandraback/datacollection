import sys


def getBit(n, index):
    return  (n & (1<<index)) > 0


# main()

# read 1 number, use it to control the loop
for tc in xrange(1, int(sys.stdin.readline())+1):
    # read 2 numbers
    n = [int(w) for w in sys.stdin.readline().split()]
    del n[0]
    # print n
    # n = sorted(n)
    # print 2**len(n)
    found = False
    for i in xrange(2**len(n)):
        tomar1 = []
        tomar2 = []
        for l in xrange(len(n)):
            if getBit(i,l) == 1:
                tomar1.append(n[l])
            else:
                tomar2.append(n[l])
        if len(tomar1) == 0 or len(tomar2) == 0:
            continue

        s1 = sum(tomar1)
        if tomar2[0] > s1:
            continue
        # tomar todos los subconjuntos de tomar2 y ver si ellos
        # pueden sumar lo mismo que la suma1
        # sacamos del conjunto tomar2 aquellos elementos que ya son mas grandes
        # que s1
        t2 = []
        for x in tomar2:
            if x <= s1:
                t2.append(x)
        tomar2 = t2
        l2 = len(tomar2)
        for j in xrange(2**l2):
            tomar3 = []
            s3 = 0
            for t3 in xrange(l2):
                if getBit(j,t3) == 1:
                    s3 += tomar2[t3]
                    if s3 > s1:
                        break
                    tomar3.append(tomar2[t3])
            if sum(tomar3) == s1:
                # print "Found! ", tomar1, " = ", s1, tomar3, " = ", s3
                found = True
                break

        # print "case ", i, " ", tomar1, tomar3
        if found:
            break

    best = 0
    if found:
        print 'Case #%d: ' % (tc)
        for x in tomar1:
            print x, 
        print
        for x in tomar3:
            print x,
        print
    else:
        print 'Case #%d:' % (tc), "Impossible"


