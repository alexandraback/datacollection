__author__ = 'Peihong'

def war(A, B):
    B_cpy = B[:]
    B_cpy.sort()

    ks = 0
    for x in A:
        for i in range(len(B_cpy)):
            if B_cpy[i] > x:
                B_cpy[i] = -1
                ks = ks+1
                break

    return len(A)-ks

def dwar(A, B):
    A_cpy = A[:]
    B_cpy = B[:]

    A_cpy.sort()
    B_cpy.sort()

    ks = 0
    ns = 0
    for i in range(len(A)):
        x = A_cpy[0]
        y = B_cpy[0]

        if x < y:
            B_cpy.pop()
            A_cpy.pop(0)
            ks = ks + 1
        else:
            B_cpy.pop(0)
            A_cpy.pop(0)
            ns = ns + 1
    return ns

def solve(A, B):
    so = 0
    s = 0

    so = dwar(A, B)
    s = war(A, B)

    return [so, s]

if __name__ == "__main__":
    f = open('D-small-attempt0.in', 'r')
    fout = open('D-small-attempt0.out', 'w')

    cases = int(f.readline())
    for i in range(cases):
        nblocks = int(f.readline())
        naomi = map(float, f.readline().split())
        ken = map(float, f.readline().split())

        so, s = solve(naomi, ken)

        print 'Case #%d: %d %d' % (i+1, so, s)

        fout.write('Case #%d: %d %d\n' % (i+1, so, s))

    f.close()
    fout.close()
