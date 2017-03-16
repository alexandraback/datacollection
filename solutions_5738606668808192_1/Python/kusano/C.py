def solve(N, J):
    j = 0
    c = 0
    while j<J:
        t = "1"+format(c, "b").zfill(N-2)+"1"
        D = []
        for b in range(2, 11):
            a = int(t, b)
            d = 2
            while d*d<=a and d<=100:
                if a%d==0:
                    D += [d]
                    break
                d += 1
            else:
                break
        if len(D)==9:
            print t, " ".join(map(str, D))
            j += 1
        c += 1

for t in range(input()):
    N,J = map(int, raw_input().split())
    print "Case #%s:" % (t+1)
    solve(N, J)
