for t in range(int(input().strip())):
    s = input().strip()
    plus = [-1, -1]
    minus = [-1, -1]
    if s[0] == '-':
        plus[0] = 1
        minus[0] = 0
    else:
        plus[0] = 0
        minus[0] = 1
    for i in range(1, len(s)):
        if s[i] == '-':
            plus[i % 2] = 1 + minus[(i - 1) % 2]
            minus[i % 2] = minus[(i - 1) % 2]
        else:
            plus[i % 2] = plus[(i - 1) % 2]
            minus[i % 2] = 1 + plus[(i - 1) % 2]
    print('Case #%d: %d' % (t + 1, plus[(len(s) - 1) % 2]))
