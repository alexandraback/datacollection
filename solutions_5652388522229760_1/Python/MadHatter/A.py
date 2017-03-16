__author__ = 'dkopiychenko'

def solve(n):
    if n == 0: return 'INSOMNIA'
    i = 1
    g = set([])
    while True:
        s = list(str(i*n))
        g.update(s)
        if len(g) == 10: return i*n
        i += 1

t = int(raw_input())
for i in xrange(t):
    n = int(raw_input())
    print 'Case #' + str(i+1) + ': ' + str(solve(n))