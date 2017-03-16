"""
2 -> 1
3 -> 2
4 -> 4
5 -> 8
maximum number of paths is 2^(b - 2).


84211
-----
01000
00100
00011
00001
00000
"""

def solve(b, m):
    if m > (1 << (b - 2)):
        return None

    matrix = []
    start_score = 1 if b <= 4 else (1 << (b - 4))

    d = (1 << (b - 2)) - m
    for i in range(b):
        row = [0] * b
        for j in range(i + 1, b):
            row[j] = 1

        score = start_score
        for j in range(i + 2, b):
            if score <= d:
                row[j] = 0
                d -= score
            score = max(1, score >> 1)

        matrix.append(row)
        start_score = max(1, start_score >> 1)

    return matrix

def main():
    T = int(input())
    for case_num in range(1, T + 1):
        b, m = map(int, input().split())
        matrix = solve(b, m)
        if matrix is None:
            print("Case #{0}: IMPOSSIBLE".format(case_num))
        else:
            print("Case #{0}: POSSIBLE".format(case_num))
            for row in matrix:
                print(''.join(map(str, row)))

main()
