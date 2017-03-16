def ring_area(r, n):
    """
    (int) -> int

    The area of the n-th ring in pi.
    """
    return 4 * n + 2 * r - 3


def total_ring_area(r, n):
    """
    (int) -> int

    Sum of areas of the first n rings in pi.
    """
    return 2 * (n ** 2) + (2 * r - 1) * n


def find_maximum(r, t):
    """
    (int, int) -> int

    Finds the maximun rings can be drawn with radius starting from r cm,
    total paint of t mL where 1 mL paint can be used to draw an area of
    pi cm^2.
    """
    lo, hi = 1, t
    while (lo < hi - 1):
        mid = (lo + hi) / 2
        cost = total_ring_area(r, mid)
        if (cost == t):
            return mid
        elif (cost < t):
            lo = mid
        else:
            hi = mid
    if (total_ring_area(r, hi) > t):
        return lo
    else:
        return hi


if __name__ == '__main__':
    import sys
    try:
        fname = sys.argv[1]
        try:
            fin = open(fname, 'r')
            case_count = fin.readline()
            for c in range(int(case_count)):
                r, t = map(int, fin.readline().split(' '))
                print "Case #{0}: {1}".format(c + 1, find_maximum(r, t))
        except IOError:
            print "File", fname, "is not accessible."
    except IndexError:
        print "Please specify name of the input file."
    
