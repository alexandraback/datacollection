import sys

def pairs(l):
    p = []
    for i in range(0, len(l), 2):
        p.append((l[i], l[i + 1]))
    return p

def find(series, n):
    for i, s in enumerate(series):
        if s[1] == n:
            return i

def solve(A, B, res=0):
    if not A or not B:
        return res
    atop = A[0]
    btop = B[0]
    if atop[1] == btop[1]:
        if atop[0] == btop[0]:
            res += atop[0]
            A = A[1:]
            B = B[1:]
        elif atop[0] > btop[0]:
            res += btop[0]
            B = B[1:]
            A[0] = (atop[0] - btop[0], atop[1])
        else:
            res += atop[0]
            A = A[1:]
            B[0] = (btop[0] - atop[0], btop[1])
    else:
        s1 = solve(A[1:], B[1:], res)
        bina = find(A, btop[1])
        ainb = find(B, atop[1])
        if bina is None and ainb is None:
            A = A[1:]
            B = B[1:]
        elif bina is None:
            B = B[ainb:]
        elif ainb is None:
            A = A[bina:]
        elif ainb < bina:
            B = B[ainb:]
        elif bina < ainb:
            A = A[bina:]
        elif bina == ainb:
            if min(B[ainb][0], atop[0]) > min(A[bina][0], btop[0]):
                B = B[ainb:]
            else:
                A = A[bina:]
        else:
            print 'ERROR: %s, %s' % (ainb, bina)
        s2 = solve(A, B, res)
        return max(s1, s2)
    return solve(A, B, res)

inp = sys.stdin

T = int(inp.readline())
for case_number in range(1, T + 1):
    N, M = map(int, inp.readline().split())
    a = map(int, inp.readline().split())
    assert len(a) == N * 2
    A = pairs(a)
    b = map(int, inp.readline().split())
    assert len(b) == M * 2
    B = pairs(b)

    res = solve(A, B)

    print 'Case #%d: %d' % (case_number, res)

