__author__ = 'eidanch'


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        L, X = tuple(formatIntegerList(get_line()))
        line = get_line()
        yield (i+1, (L, X, line))


def handle_case(case):
    L, X, line = case
    assert len(line) == L
    extended_line = X*line
    if multiply_string(extended_line) != '-1':
        return "NO"
    top_left, top_right = '1', '-1'
    for i in xrange(0, len(extended_line)):
        top_left = multiply(top_left, extended_line[i])
        top_right = multiply(inverse(extended_line[i]), top_right)
        if top_left != 'i' or top_right != 'i':
            continue
        left, right = '1', 'i'
        for j in xrange(i+1, len(extended_line)):
            left = multiply(left, extended_line[j])
            right = multiply(inverse(extended_line[j]), right)
            if left == 'j' and right == 'k':
                return "YES"

    return "NO"


def inverse(a):
    if a == '1':
        return 1
    if a[0] == '-':
        return a[1]
    return '-' + a

def multiply(a, b):
    d = {
        '1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
        'i': {'1': 'i', 'i': '-1', 'j': 'k', 'k': '-j'},
        'j': {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i'},
        'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'},
    }
    sign = 1
    if a[0] == '-':
        sign *= -1
        a = a[1]
    if b[0] == '-':
        sign *= -1
        b = b[1]
    c = d[a][b]
    if c[0] == '-':
        sign *= -1
        c = c[1]
    return c if sign == 1 else '-' + c


def multiply_string(s):
    return reduce(multiply, s, '1')

def main():
    for i, case in standard_input():
        print "Case #%d: %s" % (i, handle_case(case))

if __name__ == '__main__':
    main()