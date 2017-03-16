def isQ(c):
    return c == '?'

def diff(A, B):
    return abs(int(A) - int(B))

def mn(A):
    return A.replace("?", "0")

def mx(B):
    return B.replace("?", "9")

def f(A, B):
    if len(A) == 0:
        return "", ""

    p = A[0]
    q = B[0]

    ansA, ansB = "", ""

    ra = A[1:]
    rb = B[1:]
    if isQ(p) and isQ(q):
        a3, b3 = f('0' + ra, '0' + rb)
        a1, b1 = f('0' + mx(ra), '1' + mn(rb))
        a2, b2 = f('1' + mn(ra), '0' + mx(rb))
        d3 = diff(a3, b3)
        d1 = diff(a1, b1)
        d2 = diff(a2, b2)

        ansA = a3
        ansB = b3
        d = d3

        if d1 < d:
            d = d1
            ansA, ansB = a1, b1

        if d2 < d:
            d = d2
            ansA, ansB = a2, b2

    elif not isQ(p) and not isQ(q):
        if p < q:
            ansA, ansB = p + mx(ra), q + mn(rb)
        elif p > q:
            ansA, ansB = p + mn(ra), q + mx(rb)
        else:
            ansA, ansB = f(ra, rb)
            ansA = p + ansA
            ansB = q + ansB
    else:
        if isQ(p):
            qn = int(q)
            ansA, ansB = f(q + ra, B)

            if qn > 0:
                a1, a2 = f(str(qn - 1) + ra, B)
                if diff(a1, a2) <= diff(ansA, ansB):
                    ansA, ansB = a1, a2

            if qn < 9:
                a1, a2 = f(str(qn + 1) + ra, B)
                if diff(a1, a2) < diff(ansA, ansB):
                    ansA, ansB = a1, a2
        else:
            pn = int(p)
            ansA, ansB = f(A, p + rb)
            if pn > 0:
                a1, a2 = f(A, str(pn - 1) + rb)
                if diff(a1, a2) <= diff(ansA, ansB):
                    ansA, ansB = a1, a2

            if pn < 9:
                a1, a2 = f(A, str(pn + 1) + rb)
                if diff(a1, a2) < diff(ansA, ansB):
                    ansA, ansB = a1, a2

    return ansA, ansB

def g(S):
    A, B = S.split()
    m, n = f(A, B)
    return m + " " + n

def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        word = raw_input().strip()
        print "Case #{0}: {1}".format(t, g(word))

if __name__ == "__main__":
    main()