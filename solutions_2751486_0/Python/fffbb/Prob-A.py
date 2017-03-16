def checkstr(l, n) :
    con = 0
    for i in range(len(l)) :
        if l[i] not in ('a', 'i', 'u', 'e', 'o') :
            con += 1
        else :
            con = 0
        if con >= n :
            return True
    return False

t = int(raw_input())
for casenum in range(1, t + 1) :
    l, n = raw_input().split()
    n = int(n)
    result = 0

    for st in range(len(l)) :
        for ed in range(st + 1, len(l) + 1) :
            teststr = l[st:ed]
            if len(teststr) < n : continue
            if checkstr(teststr, n) : result += 1
    print "Case #%d: %d" % (casenum, result)
