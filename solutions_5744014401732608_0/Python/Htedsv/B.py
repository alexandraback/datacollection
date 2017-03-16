import sys
import copy

N = 6
sol = {}
for N in range(1, 7):
    mat = [[0 for _ in range(N)] for x in range(N)]
    tmp = [[0 for _ in range(N)] for x in range(N)]
    sol[N] = {}
    dis = [0] * N
    for xs in range(2**15):
        for i in range(N-1):
            for j in range(N-i-1):
                mat[i][i+j+1] = xs % 2
                xs /= 2
        dis = [0] * N
        dis[0] = 1
        for i in range(1, N):
            for j in range(i):
                if mat[j][i] == 1:
                    dis[i] += dis[j]

        #for i in range(N):
        #    print mat[i]
        #print dis[N-1]
        if dis[N-1] not in sol[N]:
            sol[N][dis[N-1]] = copy.deepcopy(mat)

fin = open(sys.argv[1])
T = int(fin.readline())
for I in range(1, T+1):
    n, m = fin.readline().split(' ')
    n, m = int(n), int(m)
    print "Case #%d:"%(I),
    if m in sol[n]:
        print 'POSSIBLE'
        mat = sol[n][m]
        for i in range(n):
            print ''.join([str(_) for _ in mat[i]])
    else:
        print 'IMPOSSIBLE'

