import sys


# delete, or create size of himself


def determine_motes(A, Vs):

    Vs.sort()
    #print A, Vs
    A2, Vs2 = simplify(A, Vs)
    
    return rec(A2, Vs2)


def rec(A, Vs):

    if not Vs:
        return 0

    #print 'Called with', A, Vs

    if A > 1:
        Vs1 = sorted(Vs[:] + [A-1])
        A2, Vs11 = simplify(A, Vs1)
        o1 = 1 + rec(A2, Vs11)
    else:
        o1 = 999999999999999999

    Vs2 = Vs[:-1]
    o2 = 1 + rec(A, Vs2)

    return min(o1, o2)

def simplify(A, Vs):

    new_vs = Vs[:]

    for v in new_vs[:]:
        if v < A:
            new_vs.remove(v)
            A += v

    return A,  new_vs


if __name__ == '__main__':

    N = int(sys.stdin.readline().strip())

    for i in range(N):
        A, N = map(int, sys.stdin.readline().strip().split())
        Vs = map(int, sys.stdin.readline().strip().split())
        print 'Case #%s: %s' % (i+1, determine_motes(A, Vs))

