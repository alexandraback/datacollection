def digit(c):
    return ord(c) - ord('0')


def better(x, y):
    diff1 = abs(x[0] - x[1])
    diff2 = abs(y[0] - y[1])
    if diff1 < diff2:
        return True
    if diff1 > diff2:
        return False

    if x[0] < y[0]:
        return True
    if x[0] > y[0]:
        return False
    if x[1] < y[1]:
        return True
    return False


def better2(x, y):
    X = (int(x[0]), int(x[1]))
    Y = (int(y[0]), int(y[1]))
    return better(X, Y)


def rec(a, b, pos, A, B):
    if pos == len(a):
        return (A, B)
    c1 = a[pos]
    c2 = b[pos]
    if c1 != '?' and c2 != '?':
        return rec(a, b, pos + 1, A * 10 + digit(c1), B * 10 + digit(c2))
    if c1 == '?' and c2 == '?':
        if A < B:
            return rec(a, b, pos + 1, A * 10 + 9, B * 10)
        if A > B:
            return rec(a, b, pos + 1, A * 10, B * 10 + 9)
        best = rec(a, b, pos + 1, A * 10, B * 10)
        choice2 = rec(a, b, pos + 1, A * 10 + 1, B * 10)
        if better(choice2, best):
            best = choice2
        choice3 = rec(a, b, pos + 1, A * 10, B * 10 + 1)
        if better(choice3, best):
            best = choice3
        return best
    if c1 == '?':
        if A < B:
            return rec(a, b, pos + 1, A * 10 + 9, B * 10 + digit(c2))
        if A > B:
            return rec(a, b, pos + 1, A * 10, B * 10 + digit(c2))
        best = rec(a, b, pos + 1, A * 10 + digit(c2), B * 10 + digit(c2))
        if digit(c2) != 0:
            x = rec(a, b, pos + 1, A * 10 + digit(c2) - 1, B * 10 + digit(c2))
            if better(x, best):
                best = x
        if digit(c2) != 9:
            x = rec(a, b, pos + 1, A * 10 + digit(c2) + 1, B * 10 + digit(c2))
            if better(x, best):
                best = x
        return best
    if c2 == '?':
        if B < A:
            return rec(a, b, pos + 1, A * 10 + digit(c1), B * 10 + 9)
        if B > A:
            return rec(a, b, pos + 1, A * 10 + digit(c1), B * 10)
        best = rec(a, b, pos + 1, A * 10 + digit(c1), B * 10 + digit(c1))
        #print best
        if digit(c1) != 0:
            x = rec(a, b, pos + 1, A * 10 + digit(c1), B * 10 + digit(c1) - 1)
            if better(x, best):
                best = x
        #print best
        if digit(c1) != 9:
            x = rec(a, b, pos + 1, A * 10 + digit(c2), B * 10 + digit(c1) + 1)
            if better(x, best):
                best = x
        #print best
        return best
    raise Exception("Wasnt supposed to be here")


def pad(s, length):
    while len(s) < length:
        s = '0' + s
    return s


def brute(a, b, pos=0, cap=10):
    if pos == len(a):
        return a, b
    if a[pos] == '?' and b[pos] == '?':
        best = None
        for i in range(10):
            for j in range(10):
                if abs(i - j) > cap:
                    continue
                a = a[:pos] + str(i) + a[pos + 1:]
                b = b[:pos] + str(j) + b[pos + 1:]
                ans = brute(a, b, pos + 1)
                if best is None or better2(ans, best):
                    best = ans
        return best
    if a[pos] == '?':
        best = None
        for i in range(10):
            a = a[:pos] + str(i) + a[pos + 1:]
            ans = brute(a, b, pos + 1)
            if best is None or better2(ans, best):
                best = ans
        return best
    if b[pos] == '?':
        best = None
        for i in range(10):
            b = b[:pos] + str(i) + b[pos + 1:]
            ans = brute(a, b, pos + 1)
            if best is None or better2(ans, best):
                best = ans
        return best
    return brute(a, b, pos + 1)


def solve(a, b):
    x = brute(a, b, 0, 1)
    return str(x[0]) + ' ' + str(x[1])


t = int(raw_input())
for i in range(1, t + 1):
    s = raw_input()
    a = s.split(' ')[0]
    b = s.split(' ')[1]
    print 'Case #{}: {}'.format(i, solve(a, b))
