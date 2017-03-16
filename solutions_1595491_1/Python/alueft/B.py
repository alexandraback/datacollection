lines = int(raw_input())

for i in range(lines):
    st = raw_input().split()
    T = int(st[0])
    S = int(st[1])
    p = int(st[2])
    t_i = sorted([int(j) for j in st[3:3+T]])
    t_i.reverse()

    n = 0
    for score in t_i:
        if score >= 3*p - 2:
            n += 1
        elif score >= 3*p - 4 and S and score:
            n += 1
            S -= 1
    #print T, S, p, t_i,
    print "Case #{0}: {1}".format(i+1,n)
