__author__ = 'dkopiychenko'

def solve(d):
    l = list(d)
    l.sort()
    return ' '.join(map(str,l))

t = int(raw_input())
for i in xrange(t):
    n = int(raw_input().strip())
    d = set([])
    for j in xrange(2*n-1):
        l = map(int,raw_input().strip().split())
        for x in l:
            if x in d:
                d.remove(x)
            else: d.add(x)
    print 'Case #' + str(i+1) + ': ' + str(solve(d))