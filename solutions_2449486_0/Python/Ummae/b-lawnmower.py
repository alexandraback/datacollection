N, M = 0, 0
def cut(board, x, y, h, direction):
    global N, M
    if direction == 'R':
        for i in range(M):
            board[x][i] = h
    elif direction == 'D':
        for i in range(N):
            board[i][y] = h


def can(h, direction, goal):
    global N, M
    if direction == 'R':
        for i in range(M):
            if goal[i] > h:
                return False
    elif direction == 'D':
        for i in range(N):
            if goal[i] > h:
                return False
    return True


def solve(goal):
    global N, M
    g_rows = [row for row in goal]
    g_cols = [[goal[i][j] for i in range(N)] for j in range(M)]
    g_row_max = [max(g_rows[i]) for i in range(N)]
    g_col_max = [max(g_cols[i]) for i in range(M)]
    job_sequence = []
    for i in range(N):
        job_sequence.append(('R', g_row_max[i], g_rows[i], i))
    for i in range(M):
        job_sequence.append(('C', g_col_max[i], g_cols[i], i))
    job_sequence = sorted(job_sequence, key=lambda x:-x[1])
    board = [[100 for i in range(M)] for i in range(N)]
    while True:
        changed = False
        for job in job_sequence:
            which, h, g, i = job
            if which == 'R':
                row = board[i]
                row_max = max(row)
                if h < row_max:
                    if can(h, 'R', g):
                        changed = True
                        cut(board, i, 0, h, 'R')
            elif which == 'C':
                col = [board[j][i] for j in range(N)]
                col_max = max(col)
                if h < col_max:
                    if can(h, 'D', g):
                        changed = True
                        cut(board, 0, i, h, 'D')
            if changed:
                break
        if not changed:
            break
    if goal == board:
        return 'YES'
    else:
        return 'NO'


T = int(raw_input())
for tcase in range(T):
    N, M = map(int, raw_input().split())
    goal = []
    for i in range(N):
        goal.append(map(int, raw_input().split()))
    ret = solve(goal)
    print 'Case #%d: %s' % (tcase+1, ret)

