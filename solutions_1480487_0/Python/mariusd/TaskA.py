import sys

INPUT_FILE = 'C:\Users\Marius\Downloads\A-small-attempt0 (1).in'

def binary_search(p, points):
    s = sum(points)
    def is_enough(frac):
        score = points[p] + s * frac
        remaining_points = s * (1 - frac)
        points_diff = 0
        for index, point in enumerate(points):
            if index == p:
                continue
            if score > point:
                points_diff += score - point
        return remaining_points < points_diff

    low = 0
    high = 1
    while abs(low - high) > 1e-9:
        mid = (high + low) / 2.0
        if is_enough(mid):
            high = mid
        else:
            low = mid
    return low

def solve(points):
    return ' '.join([str(100 * binary_search(p, points)) for p in xrange(len(points))])

def main():
    try:
        file = INPUT_FILE
    except NameError:
        file = 'SampleTests.txt'
    fh = open(file)
    number_of_cases = int(fh.readline())
    for case in range(number_of_cases):
        t = [int(x) for x in fh.readline().split()]
        points = t[1:]
        result = solve(points)
        print 'Case #%s: %s' % (case + 1, result)

if __name__ == '__main__':
    try:
        sys.stdout = open('Result.txt', 'w')
        main()
    finally:
        sys.stdout = sys.__stdout__ 