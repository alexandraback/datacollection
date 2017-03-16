__author__ = 'bszikszai'

def simulate(n, t):
    res = []
    for i in range(0, n):
        res.append([])
        for j in range(0, n):
            res[i].append(1 if j > i else 0)
    if 2**(n-2) < t:
        return 'IMPOSSIBLE'
    t -= 1
    bn = "{0:b}".format(t).rjust(n-2, '0')
    for i in range(0, n-2):
        if bn[i] == '0':
            res[0][i+1] = 0
    lns = "\n".join(["".join([str(res[i][k]) for k in range(0, n)]) for i in range(0, n)])
    return "POSSIBLE\n" + lns


def solve(f):
    inp = [int(x) for x in f.readline().rstrip('\n\r ').split(' ')]
    return simulate(inp[0], inp[1])

with open('input.txt', 'r') as f:
    with open('output.txt', 'wb') as g:
        cases = int(f.readline())
        for i in range(0, cases):
            solution = solve(f)
            print "Case #%s: %s" % (i+1, solution)
            g.write("Case #%s: %s\n" % (i+1, solution))