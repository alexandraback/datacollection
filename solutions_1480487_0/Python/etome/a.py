

import sys

T = int(sys.stdin.readline())

for i in range(1,T+1):
    line = sys.stdin.readline().split(' ')
    line = map(int, line)

    N = line[0]
    X = sum(line[1:])

    print "Case #%d:" % (i),

    ls = list()
    for n in range(1,N+1):
        ls.append( (line[n], n, 0.0) )

    ls.sort()

    sm = X + ls[0][0]
    i = 1
    while i < N and 1.0 * sm / i > ls[i][0]:
        sm += ls[i][0]
        i += 1
    
    for j in range(0,i):
        a,b,c = ls[j]
        ls[j] = (a,b, max(0.0, (1.0*sm/i-a) / X) )
    
    lss = [ (b,a,c) for (a,b,c) in ls  ]
    lss.sort()

    for b,a,c in lss:
        print "%.8f" % (c*100),

    print




