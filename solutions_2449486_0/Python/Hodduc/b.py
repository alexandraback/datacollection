n = input()
for i in range(1, n+1):
    def process():
        n, m = map(int, raw_input().split())
        x = [map(int,raw_input().split()) for i in range(n)]
        def available(r, c):
            flag = [1, 1]
            for i in range(m):
                if x[r][i] > x[r][c]: flag[0] = 0
            for i in range(n):
                if x[i][c] > x[r][c]: flag[1] = 0
            return flag[0] or flag[1]

        return 'YES' if all(available(i, j) for i in range(n) for j in range(m)) else 'NO'
    print "Case #%d:" % i, process()
