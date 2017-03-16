import fractions

def solve_small(P, log):
    if (log == 0): return 0
    for puiss in range(41):
        if (P << puiss) >= (1 << log):
            return puiss

def solve(P, Q):
    g = fractions.gcd(P, Q)
    P = P/g
    Q = Q/g
    log = 0
    for i in range(41):
        if Q == (1 << i):
            log = i
            break
    else:
        return "impossible"
    return solve_small(P, log)

T = input()
for i in range(T):
    P, Q = map(int, raw_input().strip().split('/'))
    print "Case #{}: {}".format(i+1, solve(P, Q))
