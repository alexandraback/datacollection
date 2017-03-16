def m(s, x, n):
    for i in range(n):
        if s[n - i - 1] != '?' and ord(s[n - i - 1]) - ord('0') != x // (10 ** i) % 10:
            return False
    return True
for t in range(int(input())):
    c, j = input().split()
    n, v = len(c), (1000, 2000)
    for x in range(10 ** n):
        if not m(c, x, n):
            continue
        for y in range(10 ** n):
            if m(j, y, n) and abs(x - y) < abs(v[0] - v[1]):
                v = (x, y)
    print('Case #{}: {} {}'.format(t + 1, str(v[0]).zfill(n), str(v[1]).zfill(n)))
