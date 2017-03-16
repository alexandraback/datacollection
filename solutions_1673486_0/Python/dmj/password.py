import sys

def solve(total, probs):
    M = len(probs)
    x = 1
    all_probs = []
    for p in probs:
        x *= p
        all_probs.append(x)

    # return and go
    
    best = 1 + total + 1

    all_probs.reverse()
    for kk in xrange(M):
        p = all_probs[kk]
        s = 2 * kk + total - M + 1 + (1-p) * (total + 1)

        if s < best:
            best = s

    return best
    
        



def main():
    import sys
    T = int(sys.stdin.readline())
    for case in xrange(1,T+1):
        typed, total = map(int, sys.stdin.readline().strip().split())
        probs = map(float, sys.stdin.readline().split())
        r = solve(total, probs)
        print "Case #%d: %f" % (case, r)

if __name__ == "__main__":
    main()



