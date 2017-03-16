def problem():
    T = int(raw_input()) + 1
    for t in range(1,T):
        N = int(raw_input()) 
        found = {}
        result = []
        for h in range(N * 2 - 1):
            raw = map(int, raw_input().strip().split(' '))
            for r in raw:
                if r in found:
                    found[r] = found[r] + 1
                else:
                    found[r] = 1
        for key in found:
            value = found[key]
            if value % 2 == 1: 
                result.append(key);
        result.sort();
        print 'Case #{0}: {1}'.format(t, ' '.join(map(str, result)));
problem()