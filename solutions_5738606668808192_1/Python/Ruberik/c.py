T = int(raw_input())

for i in range(1, T+1):
    N, J = map(int, raw_input().split(' '))
    print 'Case #%d:' % i
    for x in range(J):
        format_str = '{0:0%db}' % ((N - 4) / 2)
        short = format_str.format(x)
        lng = ''.join([x + x for x in short])
        result = '11%s11' % lng
        print result,
        for base in range(2, 11):
            print base + 1,
            assert int(result, base) % (base + 1) == 0
        print
