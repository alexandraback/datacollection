def find_maximum_iter(i, e_left, e, r, n, v, memo):
    """
    (int, int, int, int, int, [int], [int][int]) -> int

    Recursive step of `find_maximum'; calculates the maxium gains starting
    with the i-th task.
    """
    if (i == n):
        return 0
    if (memo[i][e_left] > -1):
        return memo[i][e_left]
    max_so_far = -1
    for spend in range(e_left + 1):
        next_max = find_maximum_iter(i + 1,
                min(e, e_left - spend + r),
                e, r, n, v, memo)
        if (next_max < 0):
            continue
        current = v[i] * spend + next_max
        if (current > max_so_far):
            max_so_far = current
    memo[i][e_left] = max_so_far
    return max_so_far


def find_maximum(e, r, n, v):
    """
    (int, int, int, [int]) -> int

    Finds the maximun gains daily tasks, starting with e joules initially,
    each recovery of r joules, n tasks, and a list of gains per task
    """
    memo = [[-1 for i in range(e + 1)] for j in range(n)]
    return find_maximum_iter(0, e, e, r, n, v, memo)


if __name__ == '__main__':
    import sys
    try:
        fname = sys.argv[1]
        try:
            fin = open(fname, 'r')
            case_count = fin.readline()
            for c in range(int(case_count)):
                e, r, n = map(int, fin.readline().split(' '))
                v = map(int, fin.readline().split(' '))[:n]
                print "Case #{0}: {1}".format(c + 1,
                                                find_maximum(e, r, n, v))
        except IOError:
            print "File", fname, "is not accessible."
    except IndexError:
        print "Please specify name of the input file."
    
