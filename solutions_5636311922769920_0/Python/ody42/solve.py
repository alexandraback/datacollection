import sys
import math


# Not entirely sure if this is correct.
def maybe_solve(K, C, S):
    needed_checks = int(math.ceil(float(K) / C))

    if S < needed_checks:
        return 'IMPOSSIBLE'

    picks = []
    offsets = iter(range(K) * needed_checks * C)
    for _ in xrange(needed_checks):
        ind = 1
        for mult in xrange(C):
            ind += offsets.next() * K ** (C-1-mult)
        picks.append(ind)
    
    return picks

def solve_small(K, C, S):
    # In the "small" test set, S is guaranteed to be equal to K.
    #
    # This way, testing the first S==K tiles will always give the
    # correct answer.
    #
    # Proof:
    #
    # If ORIG[0] == G, then the first tile of the final fractal will
    # also be G, so that we'll know there is Gold.
    # If ORIG[0] == L, then the first K tiles of the fractal, at any
    # complexity level (including given C), will be equal to the
    # original sequence. So, by testing them all, we will know if
    # there's any Gold.

    assert K == S

    return range(1, K+1)


def solve(K, C, S):
    #return solve_small(K, C, S)
    return maybe_solve(K, C, S)

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        K, C, S = map(int, sys.stdin.readline().strip().split())
        SOL = solve(K, C, S)
        if SOL == 'IMPOSSIBLE':
            ans = SOL
        else:
            ans = ' '.join(str(x) for x in SOL)
        print 'Case #%s: %s' % (i+1, ans)

if __name__ == '__main__':
    main()
