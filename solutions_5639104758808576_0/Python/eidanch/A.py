__author__ = 'eidanch'

def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int,s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        line = get_line()
        smax, slst = line.split(' ')
        smax = int(smax)
        lst = [int(c) for c in slst]
        yield (i+1, (smax, lst))


def handle_case(case):
    smax, lst = case
    assert len(lst) == smax + 1
    result = 0
    current = 0
    for s in range(0, smax + 1):
        #print smax, lst, s, current,result
        if current < s:
            result += s - current
            current = s
        current += lst[s]
    return result


def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()