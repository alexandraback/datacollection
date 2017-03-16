def readints():
    return [int(X) for X in input().split(' ')]

def add(idx, row, col):
    rows[idx] = pairs[idx][0]
    cols[idx] = pairs[idx][1]
    diff = [X for X in todo if row[X] != col[X]]
    for X in diff: todo.remove(X)
    for X in diff:
        if pairs[X][0][idx] == rows[idx][X]: add(X, pairs[X][1], pairs[X][0])
        else: add(X, pairs[X][0], pairs[X][1])

for C in range(int(input())):
    N = int(input())
    data = [readints() for X in range(2*N-1)]
    rest = data
    pairs = []
    for idx in range(N):
        m = min(X[idx] for X in rest)
        pairs.append([X for X in rest if X[idx] == m])
        rest = [X for X in rest if X[idx] != m]

    solo = [X for X in pairs if len(X)==1][0][0]
    sidx = pairs.index([solo])

    rows = [None] * N
    cols = [None] * N
    diff = set()
    todo = set(range(N))
    todo.remove(sidx)
    while len(todo) > 0:
        idx = todo.pop()
        add(idx, pairs[idx][0], pairs[idx][1])

    col = False
    for X in range(N):
        if X == sidx: continue
        if cols[X][sidx] != solo[X]: col = True

    if not col:
        rows[sidx] = solo
        val = [rows[X][sidx] for X in range(N)]
    else:
        cols[sidx] = solo
        val = [cols[X][sidx] for X in range(N)]

    print("Case #{}: {}".format(1+C, ' '.join(str(X) for X in val)))
            

