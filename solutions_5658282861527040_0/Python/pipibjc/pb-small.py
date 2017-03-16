import sys

T = int(sys.stdin.readline())

for t in range(T):
    strs = sys.stdin.readline().strip().split(' ')
    A = int(strs[0])
    B = int(strs[1])
    K = int(strs[2])

    ans = 0
    for a in range(A):
        for b in range(B):
            if a&b < K:
                ans += 1
    print "Case #%d: %d"%(t+1, ans)
