#!/usr/bin/env python


def main():
    count = int(raw_input())
    for case in xrange(1, count+1):
        (x, y) = [ int(n) for n in raw_input().split() ]
        #print x,y
        path = solve(x, y, 1, [])
        #print path
        print "Case #%d: %s" %(case,"".join(path))


def solve(x, y, step, path):
    #print x, y, step, path
    if x == 0 and y == 0:
        return path
    big = max(abs(x), abs(y))
    if (big > step * 1/2):
        if abs(x) == big:
            if x > 0:
               path.append('E')
               solve(x - step, y, step + 1, path)
            else:
                path.append('W')
                solve( x + step, y, step + 1, path)
        else:
            if y > 0:
                path.append('N')
                solve( x, y - step, step + 1, path)
            else:
                path.append('S')
                solve(x, y + step, step + 1, path)
    else:
        path.extend(('W','E')[::1 if x > 0 else -1] * abs(x))
        path.extend(('S','N')[::1 if y > 0 else -1] * abs(y))
    return path

main()



