__author__ = 'dkopiychenko'

def solve(b,m):
    if m > 2**(b-2): return False, []
    r = [[0 if i <= j else 1 for i in xrange(b)] for j in xrange(b)]
    if m == 2**(b-2): return True, r
    s = bin(m)[2:]+'0'
    s = '0'*(b-len(s))+s
    r[0] = map(int,s)
    return True, r

t = int(raw_input())
for i in xrange(t):
    b,m = map(int,raw_input().strip().split())
    p,l = solve(b,m)
    if p:
        print 'Case #' + str(i+1) + ': ' + 'POSSIBLE'
        for x in l:
            print ''.join(map(str,x))
    else:
        print 'Case #' + str(i+1) + ': ' + 'IMPOSSIBLE'

