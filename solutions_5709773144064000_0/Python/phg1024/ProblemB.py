__author__ = 'Peihong'

def solve(C, F, X, P):
    t = []
    t0 = 0
    N = 131072
    for i in range(N):
        tcur = t0 + X / P
        t.append(tcur)
        t0 = t0 + C / P
        P = P + F

    tmin = t[0]
    for i in range(N):
        tmin = min(tmin, t[i])

    return tmin

if __name__ == "__main__":
    f = open('B-small-attempt2.in', 'r')
    fout = open('B-small-attempt2.out', 'w')
    cases = int(f.readline())
    for i in range(cases):
        params = map(float, f.readline().split())
        C, F, X = params
        res = solve(C, F, X, 2)
        print 'Case #%d: %f' % (i+1, res)
        fout.write('Case #%d: %f\n' % (i+1, res))

    f.close()
    fout.close()
