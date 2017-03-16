
import sys

T = int(sys.stdin.readline())

for i in range(1,T+1):
    N = int(sys.stdin.readline())

    twos = list()
    ones = list()

    for l in range(N):
        line = sys.stdin.readline().split(' ')
        one, two = int(line[0]), int(line[1])

        twos.append( (two, l) )
        ones.append( (one, l) )

    ones.sort()
    twos.sort()

    p1 = 0
    p2 = 0

    stars = 0
    levels = 0
    compl = [0 for x in range(N)]

    lastp1 = -1
    lastp2 = -1
    failed = False
    while (lastp1!=p1 or lastp2!=p2):
        lastp1 = p1
        lastp2 = p2

        while p2<N and twos[p2][0] <= stars:
            stars += 2 - compl[twos[p2][1]]
            compl[twos[p2][1]] = 2
            levels += 1
            p2+=1

        while p1<N and compl[ ones[p1][1] ] > 1:
            p1+=1

        if p2==N:
            break

        if p1<N and ones[p1][0] <= stars:
            stars += 1
            compl[ones[p1][1]] = 1
            levels += 1
            p1+=1
        else:
            failed = True
            break

    while p1<N and compl[ ones[p1][1] ] > 1:
        p1+=1
        
    if not failed:
        print "Case #%d: %d" % (i, levels)
    else:
        print "Case #%d: Too Bad" % (i)







