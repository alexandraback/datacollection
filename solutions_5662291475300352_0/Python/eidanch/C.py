__author__ = 'eidanch'


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        N = int(get_line())
        lst = list()
        for j in xrange(N):
            lst.append(tuple(formatIntegerList(get_line())))
        yield (i+1, lst)


def handle_case(case):
    lst = case
    if len(lst) == 1:
        D, H, M = lst[0]
        lst = [(D, 1 , M), (D, 1, M+1)]
    if len(lst) == 2:
        D1, H1, M1 = lst[0]
        assert H1 == 1
        D2, H2, M2 = lst[1]
        assert H2 == 1
        if M1 == M2:
            return 0
        elif M1 > M2:
            T = (360.0 - D1)/M1
            E = D2 + T*360.0/M2
            if D1 == D2:
                E -= 360
            return 0 if E >= 360 else 1
        elif M1 < M2:
            T = (360.0 - D2)/M2
            E = D1 + T*360.0/M1
            if D1 == D2:
                E -= 360
            return 0 if E >= 360 else 1
    return None


def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()