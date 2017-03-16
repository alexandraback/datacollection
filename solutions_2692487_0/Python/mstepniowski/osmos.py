def osmos(A, motes):
    if A <= 1:
        return len(motes) # special case: can't eat anything

    motes.sort()
    P = [0] * len(motes)
    for i, mote in enumerate(motes):
        while A <= mote:
            A += A - 1 # add the largest possible mote eatable by A
            P[i] += 1
        A += mote

    needed_additions = sum(P)
    needed_moves = min_needed_moves = needed_additions

    # Try to eat the additions
    for p in reversed(P):
        needed_moves = needed_moves - p + 1
        min_needed_moves = min(min_needed_moves, needed_moves)

    return min_needed_moves


def read_numbers(line):
    if line[-1] == '\n':
        line = line[:-1]
    return [int(x) for x in line.split()]


if __name__ == '__main__':
    import sys
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        pattern = []
        A, N = read_numbers(sys.stdin.readline())
        motes = read_numbers(sys.stdin.readline())
        print "Case #{}: {}".format(i, osmos(A, motes))
