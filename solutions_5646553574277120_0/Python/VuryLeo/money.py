import sys

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        c, d, v = map(int, sys.stdin.readline().split())
        ds = map(int, sys.stdin.readline().split())
        f = [False for i in range(v + 1)]
        f[0] = True
        for p in ds:
            for pp in range(c):
                for i in range(p, v + 1)[::-1]:
                    f[i] = f[i] or f[i - p]
        #print f
        ans = 0
        for p in range(v + 1):
            if not f[p]:
                #print p, f[p]
                ans = ans + 1
                for pp in range(c):
                    for j in range(p, v + 1)[::-1]:
                        f[j] = f[j] or f[j - p]
                #print f
        sys.stdout.write("{}\n".format(ans))

