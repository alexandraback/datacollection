import sys


def is_possible(pattern):
    heights = {}
    for i, row in enumerate(pattern):
        for j, square in enumerate(row):
            heights.setdefault(square, [])
            heights[square].append((i, j))
    heights = iter(sorted(heights.items(), key=lambda item: item[0], reverse=True))

    highest, squares = next(heights)
    #current = [[highest for square in row] for row in pattern]
    for height, squares in heights:
        for i, j in squares:
            if sorted(pattern[i], reverse=True)[0] > height:
                if sorted([row[j] for row in pattern], reverse=True)[0] > height:
                    return 'NO'
    return 'YES'


inp = sys.stdin

T = int(inp.readline())
for case_number in range(1, T + 1):
    N, M = map(int, inp.readline().split())
    field = [map(int, inp.readline().split()) for _ in range(N)]
    print 'Case #%d: %s' % (case_number, is_possible(field))
