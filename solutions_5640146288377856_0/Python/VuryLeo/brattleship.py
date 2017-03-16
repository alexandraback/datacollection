import sys

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        r, c, w = map(int, sys.stdin.readline().split())
        ans = 0
        if w == 1:
            ans = r * c
        else:
            while c > w * 2 - 1:
                ans = ans + 1
                c = c - w
            ans = ans + min(w + 1, c)
        sys.stdout.write("{}\n".format(ans))

