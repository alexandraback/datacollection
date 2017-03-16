
def solve(N, A, B):
    score = 0
    compA, compB = set(), set()
    while True:
        temp = score
        for k, v in enumerate(B):
            if k not in compB and v <= score:
                score += 2 if (k not in compA) else 1
                compB.add(k)
        if len(compB) == N:
            return len(compB) + len(compA)
        if temp != score:
            continue
        possible = []
        for k, v in enumerate(A):
            if k not in compA and k not in compB and v <= score:
                possible.append((-B[k], k))
        possible.sort()
        if not possible:
            return 0
        score += 1
        compA.add(possible[0][1])

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        N = int(f.readline())
        A, B = [], []
        for j in xrange(N):
            a, b = map(int, f.readline().split(' '))
            A.append(a); B.append(b)
        res = solve(N, A, B)
        print 'Case #%d: %s' % (i + 1, res or 'Too Bad')

if __name__ == '__main__':
    import sys
    main(sys.stdin)
