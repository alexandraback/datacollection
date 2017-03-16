

T = int(input())

def findmax(S):
    for i in range(0,len(S)):
        if S[i] == '?':
            S[i] = '9'
    return S
def findmin(S):
    for i in range(0,len(S)):
        if S[i] == '?':
            S[i] = '0'
    return S

def findmindiff(C, J):
    if (len(C) == 0):
        return [], []

    if C[0] == J[0]:
        if C[0] == '?':

            diff = 100000000000000000000000000
            C[0] = '0'
            J[0] = '0'
            c, j = findmindiff(C[1:], J[1:])
            diff = abs ( int("".join([C[0]]+c)) - int("".join([J[0]]+j)) )
            c0 = C[0]
            j0 = J[0]

            C[0] = '0'
            J[0] = '1'
            c2 = findmax(C[1:])
            j2 = findmin(J[1:])
            diff2 = abs ( int("".join([C[0]]+c2)) - int("".join([J[0]]+j2)) )
            if (diff2 < diff):
                diff = diff2
                c0 = C[0]
                j0 = J[0]
                c = c2
                j = j2

            C[0] = '1'
            J[0] = '0'
            c2 = findmin(C[1:])
            j2 = findmax(J[1:])
            diff2 = abs ( int("".join([C[0]]+c2)) - int("".join([J[0]]+j2)) )
            if (diff2 < diff):
                diff = diff2
                c0 = C[0]
                j0 = J[0]
                c = c2
                j = j2

            return [c0]+c, [j0]+j

        c, j = findmindiff(C[1:], J[1:])
        return [C[0]]+c, [J[0]]+j

    if C[0] == '?':
        if (len(C) == 1):
            C[0] = J[0]
            return C, J
        diff = 100000000000000000000000000
        if (J[0] != '0'):
            C[0] = str(int(J[0])-1)
            c = findmax(C[1:])
            j = findmin(J[1:])
            diff = abs ( int("".join([C[0]]+c)) - int("".join([J[0]]+j)) )
            c0 = C[0]

        C[0] = str(int(J[0]))
        c2, j2 = findmindiff(C[1:], J[1:])
        diff2 = abs ( int("".join([C[0]]+c2)) - int("".join([J[0]]+j2)) )
        if (diff2 < diff):
            diff = diff2
            c0 = C[0]
            c = c2
            j = j2

        if (J[0] != '9'):
            C[0] = str(int(J[0])+1)
            c2 = findmin(C[1:])
            j2 = findmax(J[1:])
            diff2 = abs ( int("".join([C[0]]+c2)) - int("".join([J[0]]+j2)) )
            if (diff2 < diff):
                diff = diff2
                c0 = C[0]
                c = c2
                j = j2

        return [c0]+c, [J[0]]+j



    if J[0] == '?':
        if (len(J) == 1):
            J[0] = C[0]
            return C, J

        # print("#", C, J)
        diff = 100000000000000000000000000
        if (C[0] != '0'):
            J[0] = str(int(C[0])-1)
            j = findmax(J[1:])
            c = findmin(C[1:])
            diff = abs ( int("".join([J[0]]+j)) - int("".join([C[0]]+c)) )
            j0 = J[0]

        # print(c, j, diff)
        J[0] = str(int(C[0]))
        c2, j2 = findmindiff(C[1:], J[1:])
        diff2 = abs ( int("".join([J[0]]+j2)) - int("".join([C[0]]+c2)) )
        if (diff2 < diff):
            diff = diff2
            j0 = J[0]
            j = j2
            c = c2
        # print(c, j, diff)

        if (C[0] != '9'):
            J[0] = str(int(C[0])+1)
            j2 = findmin(J[1:])
            c2 = findmax(C[1:])
            diff2 = abs ( int("".join([J[0]]+j2)) - int("".join([C[0]]+c2)) )
            if (diff2 < diff):
                diff = diff2
                j0 = J[0]
                j = j2
                c = c2
        # print(c, j, diff)

        return [C[0]]+c, [j0]+j


    if C[0] > J[0]:
        return [C[0]] + findmin(C[1:]), [J[0]] + findmax(J[1:])
    if C[0] < J[0]:
        return [C[0]] + findmax(C[1:]), [J[0]] + findmin(J[1:])



for casei in range(1, T+1):
    print("Case #",casei,": ",sep="",end='')

    S = input()
    C, J = S.split(' ')
    C = list(C)
    J = list(J)
    c, j = findmindiff(C, J)
    print("".join(c), "".join(j), sep=" ")
