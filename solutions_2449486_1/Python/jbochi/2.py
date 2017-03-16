import itertools

def solve(n, m, lines):
    max_lines = map(max, lines)
    max_cols = [max(lines[i][j] for i in xrange(n)) for j in xrange(m)]
    def impossible(i, j):
        a = lines[i][j]
        return (a < max_lines[i]) and (a < max_cols[j])
    for i in xrange(n):
        for j in xrange(m):
            if impossible(i, j):
                return "NO"
    return "YES"

with open("input2.txt") as f:
    file_lines = f.readlines()
    file_lines = map(lambda l: l.strip(), list(file_lines))
    l = 0
    for i in range(int(file_lines[0])):
        l += 1
        n, m = map(int, file_lines[l].split(' '))
        lines = map(lambda l: map(int, l.split()), file_lines[l+1:l+n+1])
        l += n
        print "Case #%d: %s" % (i + 1, solve(n, m, lines))
