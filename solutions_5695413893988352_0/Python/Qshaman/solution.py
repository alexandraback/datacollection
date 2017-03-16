def is_digit(c):
    return '0' <= c <= '9'

def diff(l1, l2):
    return abs(int(''.join(l1)) - int(''.join(l2)))

def sol(c, j):
    ans1 = ans2 = ''
    qqq = 0
    for i in range(len(c)):
        if is_digit(c[i]) and is_digit(j[i]):
            if qqq == 0 and c[i] > j[i]:
                qqq = 1
            if qqq == 0 and c[i] < j[i]:
                qqq = -1
            if qqq == 0 and c[i] == j[i]:
                qqq = 0
            ans1 += c[i]
            ans2 += j[i]
        elif not is_digit(c[i]) and is_digit(j[i]):
            ans2 += j[i]
            if qqq == 1:
                ans1 += '0'
            elif qqq == -1:
                ans1 += '9'
            else:
                ans1 += j[i]
        elif is_digit(c[i]) and not is_digit(j[i]):
            ans1 += c[i]
            if qqq == 1:
                ans2 += '9'
            elif qqq == -1:
                ans2 += '0'
            else:
                ans2 += c[i]
        elif not is_digit(c[i]) and not is_digit(j[i]):
            if qqq == 0:
                ans1 += '0'
                ans2 += '0'
            elif qqq == 1:
                ans1 += '0'
                ans2 += '9'
            elif qqq == -1:
                ans1 += '9'
                ans2 += '0'

    #1
    ans1 = list(ans1)
    ans2 = list(ans2)
    fmax = diff(ans1, ans2)
    for i in range(len(ans1)):
        if c[i] == '?' and j[i] != '?':
            cans1 = ans1[:]
            cans2 = ans2[:]
            if (int(cans1[i]) - 1 >= 0):
                cans1[i] = str(int(cans1[i]) - 1)
                for v in range(i+1, len(ans1)):
                    if c[v] == '?':
                        cans1[v] = '9'
                    if j[v] == '?':
                        cans2[v] = '0' 
                if diff(cans1, cans2) < fmax:
                    fmax = diff(cans1, cans2)
                    ans1 = cans1[:]
                    ans2 = cans2[:]
            if (int(cans1[i]) + 1 < 10):
                cans1[i] = str(int(cans1[i]) + 1)
                for v in range(i+1, len(ans1)):
                    if c[v] == '?':
                        cans1[v] = '0'
                    if j[v] == '?':
                        cans2[v] = '9'
                if diff(cans1, cans2) < fmax:
                    fmax = diff(cans1, cans2)
                    ans1 = cans1[:]
                    ans2 = cans2[:]
    for i in range(len(ans1)):
        if j[i] == '?' and c[i] != '?':
            cans1 = ans1[:]
            cans2 = ans2[:]
            if (int(cans2[i]) - 1 >= 0):
                cans2[i] = str(int(cans2[i]) - 1)
                for v in range(i+1, len(ans1)):
                    if c[v] == '?':
                        cans1[v] = '0'
                    if j[v] == '?':
                        cans2[v] = '9'
                if diff(cans1, cans2) < fmax:
                    fmax = diff(cans1, cans2)
                    ans1 = cans1[:]
                    ans2 = cans2[:]
            if (int(cans2[i]) + 1 < 10):
                cans2[i] = str(int(cans2[i]) + 1)
                for v in range(i+1, len(ans1)):
                    if c[v] == '?':
                        cans1[v] = '9'
                    if j[v] == '?':
                        cans2[v] = '0'
                if diff(cans1, cans2) < fmax:
                    fmax = diff(cans1, cans2)
                    ans1 = cans1[:]
                    ans2 = cans2[:]
    return ' '.join([''.join(ans1), ''.join(ans2)])

T = int(raw_input())
for i in xrange(T):
    (c, j) = raw_input().split()
    print 'Case #%d: %s' % (i+1, sol(c, j))
