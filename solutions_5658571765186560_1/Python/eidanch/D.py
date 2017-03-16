__author__ = 'eidanch'


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        lst = formatIntegerList(get_line())
        yield (i+1, (lst))


def handle_case(case):
    X, R, C = tuple(case)
    R , C = max(R, C), min(R, C)
    if R < X or (R*C) % X > 0:
        return 'RICHARD'
    if X == 1:
        return 'GABRIEL'
    if X == 2:
        return 'GABRIEL'
    if X == 3:
        if C == 1:
            return 'RICHARD'
        if C >= 2:
            return 'GABRIEL'
    if X == 4:
        if C < 3:
            return 'RICHARD'
        if C >= 3:
            return 'GABRIEL'
    if X == 5:
        if C < 3:
            return 'RICHARD'
        if C >= 3:
            return 'GABRIEL'
    if X == 6:
        if C < 3:
            return 'RICHARD'
        if C >= 3:
            return 'GABRIEL'
    if X >= 7:
        return "RICHARD"

    return "Don't Know"

def main():
    for i, case in standard_input():
        print "Case #%d: %s" % (i, handle_case(case))

if __name__ == '__main__':
    main()
