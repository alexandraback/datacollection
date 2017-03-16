import sys


def grid_solver(R, C, M):
    A = R * C - M
    grid = generate_grid(R, C, '*')
    if M == 0:
        grid = generate_grid(R, C, '.')
        grid[0][0] = 'c'
    elif A == 1:
        grid[0][0] = 'c'
    elif R == 1:
        for c in range(1, A):
            grid[0][c] = '.'
    elif C == 1:
        for r in range(1, A):
            grid[r][0] = '.'
    elif A == 2 or A == 3:
        return "Impossible"
    else:
        ok, layout = triangular(R, C, A)
        if not ok:
            return "Impossible"
        else:
            for row in range(0, len(layout)):
                for col in range(0, layout[row]):
                    grid[row][col] = '.'
    grid[0][0] = 'c'
    return '\n'.join([''.join(row) for row in grid])


def generate_grid(R, C, s = '*'):
    results = []
    for row in range(0, R):
        new_row = []
        for col in range(0, C):
            new_row.append(s)
        results.append(new_row)
    return results


def triangular(R, C, A):
    for col in range(C, 1, -1):
        if A >= 2 * col:
            ok, subresults = triangular_impl(R - 2, col, A - 2 * col)
            if ok and subresults[-1] != 1:
                results = [col, col]
                results.extend((subresults))
                return (True, results)
    return (False, [])


def triangular_impl(R, C, A):
    if R == 0:
        return (A == 0, [A])
    if A == 1:
        return (False, [A])
    if A <= C:
        return (True, [A])
    for col in range(C, -1, -1):
        if A >= col:
            ok, subresults = triangular_impl(R - 1, col, A - col)
            if ok and subresults[-1] != 1:
                results = [col]
                results.extend(subresults)
                return (True, results)
    return (False, [])


def solve():
    num_cases = int(sys.stdin.readline())
    for case in range(1, num_cases + 1):
        R, C, M = map(int, sys.stdin.readline().split())
        result = grid_solver(R, C, M)
        print("Case #" + str(case) + ":\n{}".format(result))

if __name__ == "__main__":
    solve()
