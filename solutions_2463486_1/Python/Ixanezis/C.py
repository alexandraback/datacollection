import sys
from bisect import bisect, bisect_left

def ispalindrome(x):
    s = str(x)
    return s[:len(s)/2] == s[::-1][:len(s)/2]

def DFS(cur, maxlen):
    if cur:
        yield cur

    if maxlen == len(cur): return
    if len(cur) >= 22 and cur.count('0') <= 16: return
    
    iter = '01' if cur else '12'
    for elem in iter:
        for ans in DFS(cur + elem, maxlen):
            yield ans
            
    yield cur + '2'

squares = set([9])
for s in DFS('', 20):
    rev = s[::-1]
    
    for x in [int(s + rev), int(s + rev[1:])]:
        if ispalindrome(x*x):
            squares.add(x*x)
            
squares = sorted(squares)
t = int(sys.stdin.readline())
for i in xrange(t):
    a, b = map(int, sys.stdin.readline().strip().split())
    b = bisect(squares, b)
    a = bisect_left(squares, a)
    print 'Case #%d: %d' % (i+1, b - a)    
