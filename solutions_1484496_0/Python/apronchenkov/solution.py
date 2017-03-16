import sys

def Solve(seq):
    select = [0] * len(seq)
    a = 0
    b = 0
    while a != b or a == 0:
#        print select
        i = 0
        while i < len(select) and select[i] == 2:
            select[i] = 0
            b = b - seq[i]
            i = i + 1
        if i == len(select):
            return (None, None)
        elif select[i] == 0:
            select[i] = 1
            a = a + seq[i]
        elif select[i] == 1:
            select[i] = 2
            a = a - seq[i]
            b = b + seq[i]
    a = []
    b = []
    for i in xrange(len(select)):
        if select[i] == 1:
            a.append(seq[i])
            select[i]
        elif select[i] == 2:
            b.append(seq[i])
    return (a, b)


numberOfCases = int(sys.stdin.readline())
for case in xrange(numberOfCases):
    token = map(int, sys.stdin.readline().split())

    a, b = Solve(token[1:1 + token[0]])    
    print "Case #%d:" % (case + 1)
    if a and b:
        print ' '.join(map(str,a))
        print ' '.join(map(str,b))
    else:
        print 'Impossible'
