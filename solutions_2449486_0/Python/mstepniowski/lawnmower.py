def lawnmower(pattern):
    """Pattern is a list of lists"""
    for h in range(1, 101):
        if not check(pattern, h):
            return False
        replace(pattern, h)
    return True


def check(pattern, h):
    # check rows
    for row in pattern:
        if all(x in (h, -1) for x in row):
            for i in range(len(row)):
                if row[i] == h:
                    row[i] = -h
    # check columns
    for column_idx in range(len(pattern[0])):
        if (any(pattern[i][column_idx] == h for i in range(len(pattern)))
            and not all(pattern[i][column_idx] in (h, -h, -1) for i in range(len(pattern)))):
            return False
    return True


def replace(pattern, h):
    for i in range(len(pattern)):
        for j in range(len(pattern[i])):
            if pattern[i][j] in (h, -h):
                pattern[i][j] = -1


def read_numbers(line):
    if line[-1] == '\n':
        line = line[:-1]
    return [int(x) for x in line.split()]


if __name__ == '__main__':
    import sys
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        pattern = []
        n, m = read_numbers(sys.stdin.readline())
        pattern = [read_numbers(sys.stdin.readline()) for j in range(n)]
        print "Case #{}: {}".format(i, 'YES' if lawnmower(pattern) else 'NO')
