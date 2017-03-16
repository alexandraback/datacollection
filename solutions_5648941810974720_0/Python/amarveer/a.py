import sys

for cases in xrange(int(sys.stdin.readline())):
    l = list(sys.stdin.readline().strip())
    num = []
    while 'Z' in l:
        num.append(0)
        for i in 'ZERO':
            del l[l.index(i)]

    while 'X' in l:
        num.append(6)
        for i in 'SIX':
            del l[l.index(i)]

    while 'U' in l:
        num.append(4)
        for i in 'FOUR':
            del l[l.index(i)]

    while 'W' in l:
        num.append(2)
        for i in 'TWO':
            del l[l.index(i)]

    while 'G' in l:
        num.append(8)
        for i in 'EIGHT':
            del l[l.index(i)]

    while 'T' in l:
        num.append(3)
        for i in 'THREE':
            del l[l.index(i)]

    while 'S' in l:
        num.append(7)
        for i in 'SEVEN':
            del l[l.index(i)]

    while 'O' in l:
        num.append(1)
        for i in 'ONE':
            del l[l.index(i)]

    while 'V' in l:
        num.append(5)
        for i in 'FIVE':
            del l[l.index(i)]

    while 'N' in l:
        num.append(9)
        for i in 'NINE':
            del l[l.index(i)]

    num.sort()
    ans = ''
    for i in num:
        ans += str(i)
    print "Case #%d: %s"%(cases+1,ans)

    
    
            
    
