import sys

# A lawn pattern is possible if each square belongs to a row or column where it is a/the max.
# A lawn pattern is going to be a list of rows, where each row is also a list.

def row_col_maxes(pattern, rows, cols):
    row_maxes = [0] * rows
    col_maxes = [0] * cols
    for r in range(rows):
        for c in range(cols):
            if pattern[r][c] > row_maxes[r]:
                row_maxes[r] = pattern[r][c]
            if pattern[r][c] > col_maxes[c]:
                col_maxes[c] = pattern[r][c]
    return row_maxes, col_maxes

def is_possible(pattern, rows, cols):
    row_maxes, col_maxes = row_col_maxes(pattern, rows, cols)

    for r in range(rows):
        for c in range(cols):
            if pattern[r][c] < row_maxes[r] and pattern[r][c] < col_maxes[c]:
                return False

    return True

if __name__ == '__main__':
    num_patterns = int(sys.stdin.readline().strip())

    for pattern_num in range(num_patterns):
        rows, cols = map(int, sys.stdin.readline().strip().split())

        pattern = []
        for r in range(rows):
            pattern.append(map(int, sys.stdin.readline().strip().split()))

        possible = 'YES' if is_possible(pattern, rows, cols) else 'NO'
        print "Case #%d: %s" % (pattern_num + 1, possible)
