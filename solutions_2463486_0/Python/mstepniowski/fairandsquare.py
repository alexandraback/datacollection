import math


def fairandsquare(a, b):
    count = 0
    for n in range(int(math.ceil(math.sqrt(a))), int(math.sqrt(b)) + 1):
        if is_palindrome(n) and is_palindrome(n ** 2):
            count += 1
    return count


def is_palindrome(n):
    sn = str(n)
    return list(sn) == list(reversed(sn))


def read_numbers(line):
    if line[-1] == '\n':
        line = line[:-1]
    return [int(x) for x in line.split()]


if __name__ == '__main__':
    import sys
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        a, b = read_numbers(sys.stdin.readline())
        print "Case #{}: {}".format(i, fairandsquare(a, b))
