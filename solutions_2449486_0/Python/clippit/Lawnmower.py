def check(rows, columns):
    rows_max = [max(x) for x in rows]
    columns_max = [max(x) for x in columns]
    for i in range(N):
        for j in range(M):
            height = rows[i][j]
            if height != rows_max[i] and height != columns_max[j]:
                return "NO"
    return "YES"


with open('B-small-attempt0.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    for t in xrange(T):
        N, M = map(int, input.pop(0).split(' ', 2))
        rows = [map(int, line.split(' ')) for line in input[:N]]
        columns = map(list, zip(*rows))
        assert N == len(rows)
        assert M == len(columns)
        del input[:N]
        f.write('Case #%d: %s\n' % (t + 1, check(rows, columns)))
