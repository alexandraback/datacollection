t = int(raw_input())
for icase in range(1, t+1):
    s = raw_input().strip()
    res = i = 0
    if s[0] == '-':
        res += 1
        while i < len(s) and s[i] == '-':
            i += 1
    while i < len(s):
        while i < len(s) and s[i] == '+':
            i += 1
        if i >= len(s):
            break
        res += 2
        while i < len(s) and s[i] == '-':
            i += 1
    print 'Case #%d: %d' % (icase, res)
