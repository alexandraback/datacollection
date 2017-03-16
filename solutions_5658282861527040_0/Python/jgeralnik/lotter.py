import math

T = input()

def solve(A, B, K):
    """
    sum(1 for a in xrange(A) for B in xrange(B) if a & b <= K else 0)
    Initially assume A, B are one less than powers of 2
    """
    # Make sure that A > B
    if A < B:
        A, B = B, A

    top_bit = K.bit_length() - 1
    A_len = A.bit_length() - 1
    B_len = B.bit_length() - 1

    if K == 0:
        return (2 ** (A_len - B_len)) * (3 ** B_len)

    # If K's top bit is set in a ^ b then the problem is recursive
    top_bit_set = solve(A>>1, B>>1, K ^ (1 << top_bit))
    # Otherwise, assure that no top bits are set and don't care about the rest
    top_bit_not_set = ((2 ** (A_len - B_len)) * (3 ** (B_len - top_bit)) * (4 ** top_bit))
    return top_bit_set + top_bit_not_set

def check(A, B, K):
    return sum(1 if ((a & b) <= K) else 0 for a in xrange(A) for b in xrange(B))

for i in xrange(T):
    print "Case #%d:" % (i + 1),
    A, B, K = map(int, raw_input().split())
    # Subtract 1 so that we can solve <= problem which is easier
    # Solution only works for powers of 2 so for now we use naive solution
    res = check(A, B, K - 1)
    print res
