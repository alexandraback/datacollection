
def solve(cont, zer, x):
    #print cont, zer
    n = len(cont)

    def beta(i):
        return cont[i] * 1.0 / x 

    def y(i):
        return beta(i) - beta(zer)

    ys = [y(i) for i in xrange(n)]
    #print ys

    res = (1 + sum(ys)) * 100.0 / n
    if res < 0:
        res = 0

    #print res

    if res/100.0 < max(ys): 
        #print 'tring again...'

        cont_new = list(cont)
        dlt = 0
        new_zer = 0
        for i in xrange(n):
            if i == zer:
                new_zer = zer - dlt
            if ys[i] > res/100.0:
                del cont_new[i - dlt]
                dlt += 1

        return solve(cont_new, new_zer, x)
    else:
        return res

    #print 'Trying', res
    #print 'total', res * x / 100.0 + cont[zer], 'points'

def solve_case(case):

    print 'Case #%i:' % case,

    inp = map(int, raw_input().split(' '))

    n, cont = inp[0], inp[1:]

    x = sum(cont)

    #print x, cont

    for i in xrange(n):
        print solve(cont, i, x),

    print 


t = int(raw_input())

for i in xrange(t):

    solve_case(i + 1)
