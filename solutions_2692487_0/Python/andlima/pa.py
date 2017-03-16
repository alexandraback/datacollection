def solve(a, i, n, motes):
    q = a
    for j in range(i, n):
        mote = motes[j]
        if mote < q:
            q += mote
        else:
            tmp = 1 + solve(q, j + 1, n, motes)
            if q > 1:
                d = 0
                while q <= mote:
                    d += 1
                    q += (q - 1)
                tmp = min(tmp, d + solve(q + mote, j + 1, n, motes))
            return tmp
    return 0

def main():
    T = int(raw_input())
    for i in range(T):
        A, N = map(int, raw_input().split())
        motes = map(int, raw_input().split())
        motes.sort()
        print 'Case #%d: %d' % (i + 1, solve(A, 0, N, motes))

main()
