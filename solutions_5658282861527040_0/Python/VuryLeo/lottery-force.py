import sys

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        m, n, k = map(int, sys.stdin.readline().split())
        ans = 0
        for i in range(m):
            for j in range(n):
                if i & j < k:
                    ans += 1
        sys.stdout.write("{}\n".format(ans))

