T = int(raw_input())

for case in range(T):
    N = int(raw_input())
    a_i, b_i = [], []
    for i in range(N):
        temp = raw_input().split()
        a_i.append(int(temp[0]))
        b_i.append(int(temp[1]))
    stars = 0
    plays = 0
    progress = True
    #print a_i, b_i
    while True:
        if not progress:
            break
        progress = False
        # look for possible 2-stars
        for i in range(len(b_i)):
            if b_i[i] <= stars and b_i[i] != -1:
                stars += (a_i[i] == -1) and 1 or 2
                plays += 1
                b_i[i] = -1
                a_i[i] = -1
                progress = True
                #print a_i, b_i, stars
        if progress:
            continue
        # look for possible 1-stars
        pos = {}
        for i in range(len(a_i)):
            if a_i[i] <= stars and a_i[i] != -1:
                pos[b_i[i]] = i
        if pos:
            #print pos, pos[max(pos.keys())]
            stars += 1
            plays += 1
            a_i[pos[max(pos.keys())]] = -1
            progress = True
            #print a_i, b_i, stars
    print "Case #{0}:".format(case+1),
    if a_i == b_i == [-1]*N:
        print plays
    else:
        print "Too Bad"
