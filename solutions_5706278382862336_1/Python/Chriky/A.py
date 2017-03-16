import codejam as gcj
import codejam.maths as mth

T = gcj.read_input('i')
for t in range(T):
    P, Q = map(int, gcj.read_input('s').split('/'))
    d = mth.gcd(P, Q)
    P, Q = P / d, Q / d
    f = mth.factorisation(Q)

    if P == Q == 1:
        answer = 0
    elif len(f) == 1 and 2 in f:
        answer = f[2]
        while P >= 2:
            P = P / float(2)
            answer -= 1
    else:
        answer = 'impossible'

    print 'Case #%i:' % (t + 1), answer