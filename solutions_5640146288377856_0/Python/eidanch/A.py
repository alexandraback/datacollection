__author__ = 'eidanch'


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        case = tuple(map(int,get_line().split(' ')))
        yield (i+1, case)


def handle_case(case):
    R, C, W = case
    if C % W == 0:
        return R*(C/W) + W - 1
    else:
        return R*(C/W + 1) + W - 1


def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()