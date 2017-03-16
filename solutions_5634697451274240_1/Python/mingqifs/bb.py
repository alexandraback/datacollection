T = int(input())

rev = {'+': '-', '-': '+'}

for i in range(1, T + 1):
    a = input().strip()
    cur = len(a) - 1
    ans = 0
    while cur >= 0:
        if a[cur] == '+':
            cur -= 1
        else:
            ed = 0
            while a[ed] == '+':
                ed += 1
            if a[0] == '+':
                a = '-' * ed + a[ed:]
                ans += 1
            ans += 1
            a = ''.join([rev[x] for x in a[:cur + 1][::-1]]) + a[cur + 1:]

    print("Case #{0}: {1}".format(i, ans))

