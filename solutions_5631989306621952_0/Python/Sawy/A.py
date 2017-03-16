def problem():
    T = int(raw_input()) + 1
    for t in range(1,T):
        S = raw_input()
        result = ''
        lastCh = '\0'
        for ch in S:
            if ch < lastCh:
                result += ch
            else:
                result = '{0}{1}'.format(ch, result)
            lastCh = result[0]
        print 'Case #{0}: {1}'.format(t, result)
problem()