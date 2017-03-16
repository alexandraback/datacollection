
if __name__ == '__main__':
    t = int(input())
    for c in range(1, t + 1):
        n, a = input().split()
        n = int(n)
        a = [int(x) for x in a]
        s = 0
        ans = 0
        for i in range(n + 1):
            if s < i:
                ans += i - s
                s = i
            s += a[i]
        print('Case #%d: %d' % (c, ans))