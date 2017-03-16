T = int(raw_input())
for t in xrange(T):
    X, R, C = (int(c) for c in raw_input().split(' '))

    def fit(w, h):
        return (w <= R and h <= C) or (w <= C and h <= R)
    if (
        X >= 7 or # loop piece impossible to fill
        (R * C) % X != 0 or # Not divisible
        any(not fit(i, X - i + 1) for i in xrange(1, X)) # Can make L shape to not fit
    ):
        ans = "RICHARD"
    else:
        # Anything else you can just kind of greedy flood fill?
        ans = "GABRIEL"

    print 'Case #' + str(t + 1) + ': ' + ans
        
