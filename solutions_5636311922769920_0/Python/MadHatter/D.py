__author__ = 'dkopiychenko'

def solve(k,c,s):
    g = k**(c-1)
    l = [1 + i*g for i in xrange(k)]
    #return 'IMPOSSIBLE'
    return ' '.join(map(str,l))

t = int(raw_input())
for i in xrange(t):
    k,c,s = map(int,raw_input().split())
    print 'Case #' + str(i+1) + ': ' + solve(k,c,s)