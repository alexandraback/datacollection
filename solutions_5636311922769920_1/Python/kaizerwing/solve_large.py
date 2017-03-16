for t in range(int(input().strip())):
    k, c, s = list(map(int, input().strip().split()))
    print('Case #%d:' % (t + 1), end = '')
    if c == 1:
        if s < k:
            print(' IMPOSSIBLE')
        else:
            for i in range(1, k + 1):
                print(' %d' % i, end = '')
            print('')
    else:
        if s < k - 1:
            print(' IMPOSSIBLE')
        else:
            for i in range(2, k + 1):
                print(' %d' % i, end = '')
            print('')
