base_income = 2

def solve(C, F, X):
    n = 0
    time = 0
    while True:
        prod = F * n + 2
        prod_after = prod + F
        cost1 = X / prod
        cost2 = X / prod_after + C / prod
        if cost2 < cost1:
            n += 1
            time += C / prod
        else:
            break

    time += X / (F*n + 2)
    return time

n = int(raw_input())

for i in xrange(n):
    C, F, X = map(float, raw_input().split())
    print 'Case #%d:' % (i + 1), solve(C, F, X)
