import sys


def read_numbers(line=None):
    if line is None:
        line = sys.stdin.readline()
    return [int(x) for x in line.split()]


def lottery(a, b, k):
    result = 0
    for x in range(a):
        for y in range(b):
            if x & y < k:
                result += 1
    return result


if __name__ == '__main__':
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        a, b, k = read_numbers()
        print "Case #%d: %s" % (i, lottery(a, b, k))
