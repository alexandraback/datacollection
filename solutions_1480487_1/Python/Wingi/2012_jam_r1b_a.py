import StringIO, sys

if len(sys.argv)>1:
    input = file(sys.argv[1]).readline
else:
    input = StringIO.StringIO("""4
2 20 10
10 76 0 0 0 0 0 0 0 0 0
4 25 25 25 25
3 24 30 21""").readline

def solve(n):
    #print n
    nSorted = sorted(set(n))
    sumN = sum(n)
    r = [0 for x in n]
    toHigh = [False for x in n]
    #print n
    while nSorted:
        m = nSorted.pop()

        #filter out all biggest cont. 
        for i in range(len(n)):
            toHigh[i] = n[i]>m

        #points to reach the best contestant
        for i in range(len(n)):
            if toHigh[i]:
                r[i] = 0
            else:
                r[i] = m-n[i]
        sumR = sum(r)
        if sumR<=sumN:
            break
    #print toHigh
    ret = [0 for x in n]
    lowCount = len(n)
    for x in toHigh:
        if x: lowCount -= 1

    rest = 1.0*(sumN - sumR)/lowCount
    #print r
    #print "Rest:", rest
    for i in range(len(n)):
        if toHigh[i]:
            ret[i] = 0
        else:
            r[i]+=rest
            ret[i] = 100*r[i]/sumN
    return " ".join(["%0.6f" % x for x in ret])

for case in range(int(input())):
    
    print "Case #%d: %s" % (case+1, solve(map(int, input().split()[1:])))


