for case in range(int(input())):
    cakes = input().strip()
    ans = sum(a != b for a, b in zip(cakes, cakes[1:]))
    ans += cakes[-1] == '-'
    print('Case #%d:' % (case+1), ans)
