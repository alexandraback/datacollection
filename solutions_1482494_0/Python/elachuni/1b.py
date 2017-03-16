#~ f = open('1b.in')
f = open('B-small-attempt2.in')

T = int(f.readline().strip())
for case in range(T):
    N = int(f.readline().strip())
    A = [None] * N
    B = [None] * N
    punch = [[False, False] for x in range(N)]
    for i in range(N):
        a, b = [int(x) for x in f.readline().strip().split()]
        A[i] = (a, b, i)
        B[i] = (b, a, i)

    A.sort(key=lambda x: x[0] * N  + (N - x[1]), reverse=True)
    B.sort(reverse=True)
    stars = 0
    turns = 0
    too_bad = False
    while B and not too_bad:
        turns += 1
        if stars >= B[-1][0]:
            b, a, i = B.pop()
            punch[i][1] = True
            if punch[i][0]:
                stars += 1
            else:
                stars += 2
        else:
            while A and punch[A[-1][2]][1]:
                A.pop()
            if not A:
                too_bad = True
            elif stars >= A[-1][0]:
                a, b, i = A.pop()
                punch[i][0] = True
                stars += 1
            else:
                too_bad = True
    if too_bad:
        print "Case #%d: Too Bad" % (case + 1)
    else:
        print "Case #%d: %s" % (case + 1, turns)
