T = input()
for t in range(T):
    n = input()
    l = map(int, raw_input().split(' '))
    l = sorted(l)
    low = 0
    high = l[n - 1]
    while high - low > 1:
        mid = (low + high) / 2
        flag = 0
        for i in range(mid):
            c = 0
            for j in range(n):
                c += l[j] / (mid - i) + int(l[j] % (mid - i) != 0) - 1
            if c <= i:
                flag = 1
                break
        if flag == 1:
            high = mid
        else:
            low = mid
    print 'Case #%d: %d' % (t + 1, high)
