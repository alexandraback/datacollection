import codejam as gcj
import codejam.maths as mth

T = gcj.read_input('i')
for t in range(T):
    N, X, Y = gcj.read_input('i i i')
    X = abs(X)
    l = (X + Y) / 2

    if X == 0:
        Z = (l + 1) * (2 * l + 1)
        if N >= Z:  answer = 1.0
        else:       answer = 0.0
    else:
        N -= l * (2 * l - 1)
        if N < Y + 1:
            answer = 0.0
        elif N >= l * 2 + Y + 1:
            answer = 1.0
        else:
            # probability at least Y heads from N
            answer = 0.0
            for i in range(Y + 1, N + 1):
                answer += mth.choose(N, i)
            answer *= 0.5**N

    print "Case #%d:" % (t + 1), answer
