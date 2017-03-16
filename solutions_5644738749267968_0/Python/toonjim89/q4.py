import sys
f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    num = int(f.readline())
    NaomiD = 0
    NaomiW = 0
    q = 0
    NaomiBlocks = []
    NaomiBlocks += [map(float, f.readline().split())]
    KenBlocks = []
    KenBlocks += [map(float, f.readline().split())]
    for i in range(num):
        for j in range(num-i-1):
            if NaomiBlocks[0][j+1]<NaomiBlocks[0][j]:
                temp = NaomiBlocks[0][j]
                NaomiBlocks[0][j] = NaomiBlocks[0][j+1]
                NaomiBlocks[0][j+1] = temp
            if KenBlocks[0][j+1]<KenBlocks[0][j]:
                temp2 = KenBlocks[0][j]
                KenBlocks[0][j] = KenBlocks[0][j+1]
                KenBlocks[0][j+1] = temp2
    for k in range(num):
        if NaomiBlocks[0][k] > KenBlocks[0][k-q]:
            NaomiD = NaomiD + 1
        else:
            q = q+1
    for k in range(num):
        j = num + 1
        p = 0
        r = 0
        count = 0
        while (NaomiBlocks[0][k] < KenBlocks[0][j-2] or KenBlocks[0][j-2] == 0) and j>1:
            if KenBlocks[0][j-2] == 0:
                p = p
                r = r+1
            else:
                p = p+1
                r = 0
            j = j-1
        if p == 0:
            count = 0
            while KenBlocks[0][count] == 0:
                count = count+1
            KenBlocks[0][count] = 0
            NaomiW = NaomiW+1
        else:
            KenBlocks[0][j-1+r] = 0
    print "Case #%d: %d %d" % (t+1,NaomiD,NaomiW)
