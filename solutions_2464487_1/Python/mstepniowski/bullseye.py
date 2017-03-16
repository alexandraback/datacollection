def required_paint(r, n):
    return (2 * r + 2 * n - 1) * n

def bullseye(r, t):
    low = 1
    high = 1000000001
    while low < high - 1:
        guess = (high - low) // 2 + low
        if required_paint(r, guess) > t:
            high = guess
        else:
            low = guess
    return low


def read_numbers(line):
    if line[-1] == '\n':
        line = line[:-1]
    return [int(x) for x in line.split()]


if __name__ == '__main__':
    import sys
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        pattern = []
        r, t = read_numbers(sys.stdin.readline())
        print "Case #%d: %d" % (i, bullseye(r, t))
