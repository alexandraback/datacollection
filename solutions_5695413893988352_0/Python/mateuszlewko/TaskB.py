t = int(raw_input())


def getRes(s1, s2, pos, firstBigger):
    for i in xrange(pos, len(s1)):
        if s1[i] == '?':
            s1[i] = '0' if firstBigger else '9'
        if s2[i] == '?':
            s2[i] = '9' if firstBigger else '0'

    # print s1, s2
    return int(''.join(s1)), int(''.join(s2))


for i in xrange(1, t + 1):
    resC, resJ = None, None
    res = 0

    C, J = raw_input().split(' ')
    C, J = list(C), list(J)

    for ind in xrange(len(C)):
        if C[ind] == J[ind] == '?':
            C2, J2 = list(C), list(J)
            C2[ind] = '0'
            J2[ind] = '1'

            Cr1, Jr1 = getRes(C2, J2, ind, False)
            ab = abs(Cr1 - Jr1)
            if resC is None or (res > ab) or (res == ab and ((resC > Cr1) or (resC == Cr1 and resJ > Jr1))):
                res = ab
                resC = Cr1
                resJ = Jr1

            C2, J2 = list(C), list(J)
            C2[ind] = '1'
            J2[ind] = '0'

            Cr1, Jr1 = getRes(C2, J2, ind, True)
            ab = abs(Cr1 - Jr1)
            # print 'er:', ab, 'res', res

            if resC is None or (res > ab) or (res == ab and ((resC > Cr1) or (resC == Cr1 and resJ > Jr1))):
                # print 'er:', ab, 'res', res

                res = ab
                resC = int(Cr1)
                resJ = int(Jr1)
                # print resC, resJ

            C[ind] = J[ind] = '0'

        elif (C[ind] == '?') ^ (J[ind] == '?'):
            C2, J2 = list(C), list(J)
            if C[ind] == '?':
                C2[ind] = '0' if J2[ind] == '0' else chr(ord(J2[ind]) - 1)
            elif J[ind] == '?':
                J2[ind] = '0' if C2[ind] == '0' else chr(ord(C2[ind]) - 1)

            Cr1, Jr1 = getRes(C2, J2, ind, J[ind] == '?')
            ab = abs(Cr1 - Jr1)
            if resC is None or (res > ab) or (res == ab and ((resC > Cr1) or (resC == Cr1 and resJ > Jr1))):
                res = ab
                # print 'bad', res
                resC = int(Cr1)
                resJ = int(Jr1)

            C2, J2 = list(C), list(J)
            if C[ind] == '?':
                C2[ind] = '9' if J[ind] == '9' else chr(ord(J[ind]) + 1)
            elif J[ind] == '?':
                J2[ind] = '9' if C[ind] == '9' else chr(ord(C[ind]) + 1)

            Cr1, Jr1 = getRes(C2, J2, ind, C[ind] == '?')
            ab = abs(Cr1 - Jr1)
            if resC is None or (res > ab) or (res == ab and ((resC > Cr1) or (resC == Cr1 and resJ > Jr1))):
                # print 'bad', res

                res = ab
                resC = Cr1
                resJ = Jr1

            if C[ind] == '?':
                C[ind] = J[ind]
            else:
                J[ind] = C[ind]

        elif C[ind] == J[ind]:
            continue
        else:
            for ii in xrange(ind, len(C)):
                if C[ii] == '?':
                    C[ii] = '9' if C[ind] < J[ind] else '0'
                if J[ii] == '?':
                    J[ii] = '0' if C[ind] < J[ind] else '9'
                # print C[ii], J[ii]
            break

    Cr1, Jr1 = int(''.join(C)), int(''.join(J))
    ab = abs(Cr1 - Jr1)
    if resC is None or (res > ab) or (res == ab and ((resC > Cr1) or (resC == Cr1 and resJ > Jr1))):
        # print 'bad', res

        res = ab
        resC = Cr1
        resJ = Jr1

    resC = str(resC)
    resJ = str(resJ)

    print 'Case #' + str(i) + ':', '0' * (len(C) - len(resC)) + resC, '0' * (len(J) - len(resJ)) + resJ
