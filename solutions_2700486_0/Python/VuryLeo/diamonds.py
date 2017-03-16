import sys

def c(n, k):
    base = 1
    for i in range(n - k + 1, n + 1):
        base = base * i
    for i in range(1, k + 1):
        base = base / i
    return base

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        p, x, y = tuple(map(int, sys.stdin.readline().split()))
        x = abs(x)
        layer = 0
        ans = 0
        number = layer * 4 + 1
        while(p >= number):
            p = p - number
            layer = layer + 1
            number = layer * 4 + 1
        if (x + y < 2 * layer):
            ans = 1
        elif (x + y > 2 * layer):
            ans = 0
        else:
            if (x == 0):
                ans = 0
            else:
                if (p < y):
                    ans = 0
                if (y < p - layer * 2):
                    ans = 1
                else:
                    for j in range(y + 1, p + 1):
                        ans = ans + c(p, j) / pow(2, p)
        sys.stdout.write("{}\n".format(ans))

