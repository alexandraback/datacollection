
def solve(N, S):
    total = float(sum(S))
    median = total * 2 / N
    winners, totalX = set(), 0
    for i, score in enumerate(S):
        if score >= median:
            winners.add(i)
        else:
            totalX += score
    Ncomp = N - len(winners)
    medianX = (totalX + total) / Ncomp

    res = []
    for i, score in enumerate(S):
        if i in winners:
            res.append(0.0)
        else:
            res.append(100.0 * (medianX - score) / total)
    return res

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        S = map(int, f.readline().split(' '))
        N = S.pop(0)
        res = map(str, solve(N, S))
        print 'Case #%d: %s' % (i + 1, ' '.join(res))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
