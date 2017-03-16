import sys

f = sys.stdin
T = int(f.readline())

def check(start, g, vis):
    if start in vis:
        return True
    nextl = g[start]
    for n in nextl:
        if n in vis:
            return True
        elif check(n, g, vis) :
            return True
        vis.append(n)
    return False

for tc in xrange(1,T+1):
    N = int(f.readline())
    graph = {}
    for i in xrange(1, N+1):
        graph[i] = [int(val) for val in f.readline().split()][1:]
    d = False
    for i in xrange(1, N+1):
        if check(i,graph,[]):
            d = True
            break
    print 'Case #%d:' % tc,
    if d:
        print 'Yes'
    else :
        print 'No'



