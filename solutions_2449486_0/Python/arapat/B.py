
import sys

T = int(sys.stdin.readline())
for loop in range(1,T+1):
    mn = sys.stdin.readline().split()
    m = int(mn[0])
    n = int(mn[1])
    data = []
    for i in range(m):
        data.append([int(x) for x in sys.stdin.readline().split()])

    hm = [0 for i in range(m)]
    vm = [0 for i in range(n)]
    for i in range(m):
        for j in range(n):
            hm[i] = max(hm[i], data[i][j])
            vm[j] = max(vm[j], data[i][j])

    result = "YES"
    for i in range(m):
        for j in range(n):
            if data[i][j] < min(hm[i], vm[j]):
                result = "NO"
    print 'Case #' + str(loop) + ': ' + result

