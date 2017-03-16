import math

f = open('B-small.in', 'r')
out = open('B-small.txt', 'w')
T = int(f.readline())

cesty = {}

for case in range(T):
    #print(case)
    B, M = list(map(int, f.readline().strip().split()))

    if pow(2, B - 2) >= M:
        out.write("Case #" + str(case + 1) + ": POSSIBLE\n")
        #print(math.log(M, 2))
        cesty = {}
        full = math.floor(math.log(M, 2)) + 1
        for i in range(B):
            cesty[i] = ['0' for j in range(B)]

        for i in range(full):
            for j in range(i + 1, full):
                cesty[i][j] = '1'
            cesty[i][B - 1] = '1'

        zvysok = M - pow(2, full - 1)

        if zvysok > 0:
            bzvysok = bin(zvysok)
            #print(bzvysok)
            cesty[B - 2][B - 1] = '1'
            for i in range(len(bzvysok) - 2):
                if bzvysok[len(bzvysok) - i - 1] == '1':
                    cesty[i + 1][B - 2] = '1'

            #print(len(bzvysok))


        for c in cesty:
            print(cesty[c])
            out.write("".join(cesty[c]) + "\n")
    else:
        out.write("Case #" + str(case + 1) + ": IMPOSSIBLE\n")