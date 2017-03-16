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
        C = 0
        # NA is sum of all new motes (A - 1), C = 1
        NA = A
        while NA <= Vs[0]:
            NA += (NA - 1) 
            C += 1
        #print 'took C=', C, 'get to A of ', NA, 'from initial ', A
        A2, Vs11 = simplify(NA, Vs)

        #print 'After skipping and simplifying', A2, Vs11, C
        o1 = C + rec(A2, Vs11)
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

