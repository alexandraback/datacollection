inf = open('./input.txt', 'r')

T = int(inf.readline())


def readline():
    row = inf.readline()
    row = [float(num) for num in row.split(' ')]
    row.sort()
    return row


def war(A, B):
    sb = 0
    for a in A:
        for bi in range(len(B)):
            b = B[bi]
            if b > a:
                del B[bi]
                sb = sb + 1
                break
    return sb


def dwar(A, B):
    sb = 0
    N = len(A)
    for i in reversed(range(N)):
        if A[-1] < B[-1]:
            sb = sb + 1
            del A[0]
            del B[-1]
        else:
            del A[-1]
            del B[-1]
    return sb


def testcace(t):
    N = int(inf.readline())
    a = readline()
    b = readline()

    if N != len(a) or N != len(b):
        print "Error!"

    w = N - war(a[:], b[:])
    dw = N - dwar(a[:], b[:])

    print "Case #%d: %d %d" % (t, dw, w)


for t in range(T):
    testcace(t + 1)
