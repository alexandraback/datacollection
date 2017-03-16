t = input()

def perim_score(n, m):
    return n * m - 4

def shrink(n, m, goal):
    # decrease the one that is larger
    # same perimeter change. But fewer stones lost
    if n > m:
        return shrink(m, n, goal)
    if perim_score(n, m-1) < goal:
        if goal > n * m - 2:
            return 2*(n-2) + 2*(m-2)
        else:
            return 2*(n-2) + 2*(m-2) - 1
    return shrink(n, m-1, goal)
    
from math import sqrt
for case in xrange(1, t+1):
    n, m, k = map(int, raw_input().split())
    # edge cases
    if n <= 2 or m <= 2:
        # all points are edge points
        print "Case #%d: %d" % (case, k)
        continue
    corners = k - (n*m - 4)
    if corners >= 0:
        border = 2*(n-2) + 2*(m-2)
        print "Case #%d: %d" % (case, border + corners)
        continue
    # the main case
    # a shortcut check?
    k += 4
    stones = 4
    
    print "Case #%d: %d" % (case, shrink(n, m, k))