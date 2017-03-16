import sys

T = int(sys.stdin.readline())

for t in range(T):
    line = sys.stdin.readline()
    A, B, K = map(int, line.strip().split(" "))

    m = A&B
    ans = 0
    for a in range(0, A):
        for b in range(0, B):
            if a&b < K:
                ans+=1
    print "Case #{}: {}".format(t+1, ans)