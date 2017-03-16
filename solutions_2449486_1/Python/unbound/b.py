
if __name__ == "__main__":
    f = open('2.in', 'r')
    o = open('2.out', 'w')

    T = int(f.readline().strip())

    for t in xrange(T):
        (N, M) = map(int, f.readline().strip().split(' '))
        row_max = [0]*N
        col_max = [0]*M
        a = []
        for r in xrange(N):
            row = map(int, f.readline().strip().split(' '))
            a.append(row)
            for c, h in enumerate(row):
                row_max[r] = max(row_max[r], h)
                col_max[c] = max(col_max[c], h)
        flag = False
        for r in xrange(N):
            for c in xrange(M):
                if a[r][c] < row_max[r] and a[r][c] < col_max[c]:
                    flag = True
                    break
            if flag:
                break
        if flag:
            s = "Case #%s: NO\n" % (t + 1)
        else:
            s = "Case #%s: YES\n" % (t + 1)
        o.write(s)
