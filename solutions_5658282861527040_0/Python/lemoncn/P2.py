fn = raw_input()
rfp = open(fn + '.in', 'r')
wfp = open(fn + '.out', 'w')
T = int(rfp.readline())


def read_array():
    return map(lambda(x): int(x), rfp.readline().split(' '))

for k in range(T):
    A, B, K = read_array()
    cnt = 0
    for i in range(A):
        for j in range(B):
            if (i & j) < K:
                cnt += 1
    ans = cnt
    result_string = 'Case #{0}: {1}\n'.format(k + 1, ans)
    wfp.write(result_string)
    print result_string