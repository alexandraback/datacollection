def probB(n):
    for i in range(0, n):
        N, M = tuple(int(s) for s in input().split())
        board = list(list(int(num) for num in input().split()) for k in range(0, N))
        rows = list(set(k for k in j if k != -1) for j in board)
        cols = list(set(row[j] for row in board if row[j] != -1) for j in range(0, M))
        emptyRowsCols = sum(1 for entry in rows if len(entry) == 0) + sum(1 for entry in cols if len(entry) == 0)
            
        last = 0
        while (emptyRowsCols != N + M):
            breakout = False
            for I in range(last + 1, 101):
                last = I
                didSomething = False
                for j in range(0, N):
                    if len(rows[j]) == 1 and I in rows[j]:
                        board[j] = [-1] * len(board[j])
                        didSomething = True
                for j in range(0, M):
                    if len(cols[j]) == 1 and I in cols[j]:
                        didSomething = True
                        for row in board:
                            row[j] = -1
                if didSomething:
                    break
                else:
                    breakout = True
            rows = list(set(k for k in j if k != -1) for j in board)
            cols = list(set(row[j] for row in board if row[j] != -1) for j in range(0, M))
            emptyRowsCols = sum(1 for entry in rows if len(entry) == 0) + sum(1 for entry in cols if len(entry) == 0)
            if breakout:
                break

        print("Case #%d: %s" % (i+1, "YES" if emptyRowsCols == N + M else "NO"))

n = int(input())
probB(n)
