T = int(raw_input())
for i in xrange(T):
    N = int(raw_input())
    case = i + 1
    result = None
    if N < 1:
        result = 'INSOMNIA'
    else:
        ds = set()
        result = N
        i = 0
        while len(ds) < 10:
            ds = ds | set(str(result))
            result += N
            i += 1
            if i > 1000000:
                print('exploded')
                break
        result -= N
    print('Case #{}: {}'.format(case, result))
