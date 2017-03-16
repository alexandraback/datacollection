import sys

def solve_single_case():
    A, N = sys.stdin.readline().split()
    A, N = int(A), int(N)
    moles = [int(x) for x in sys.stdin.readline().split()]
    assert len(moles) == N
    if A == 1:
        return N
    moles = sorted(moles)
    player = A
    min_changes = N
    current_changes = 0
    i = 0
    while i < N:
        mole = moles[i]
        if mole < player:
            player += mole
            i += 1
        else:
            remove_rest = current_changes + (N - i)
            if remove_rest < min_changes:
                min_changes = remove_rest
            player += player - 1
            current_changes += 1
        if current_changes > min_changes:
            break
    return min(min_changes, current_changes)


def main():
    T = int(sys.stdin.readline())
    for case in xrange(1, T + 1):
        solution = solve_single_case()
        print "Case #%d: %d" % (case, solution)


main()