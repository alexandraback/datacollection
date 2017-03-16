def solve(case):
    r, c, w = case
    if w == 1:
        return r*c
    elif r == 1 and c % w == 0:
        return c/w + w - 1
    elif r == 1:
        return c/w + w
    elif c % w == 0:
        return r*(c/w) + w - 1
    else:
        return r*(c/w) + w


f = open('a.in', 'r')
lines = f.readlines()

cases = [map(int, list(line.split())) for line in lines[1:]]
print cases

g = open('a.out','w')
for i in xrange(len(cases)):
    g.write('Case #' + str(i + 1) + ': ' + str(solve(cases[i])) + '\n')
g.close()
