filename = 'B-small-attempt0'
ans = False
with open(filename + '.in', 'r') as dat, open(filename + '.out', '+w') as output:
    _T = int(dat.readline())
    for _t in range(_T):
        A, B, K = list(map(int, dat.readline().strip('\n').split()))
        c = 0
        ans = 0
        for i in range(A):
            for j in range(B):
                if i & j < K:
                    ans += 1
        output.write('Case #' + str(_t + 1) + ': ' + str(ans) + '\n')
       