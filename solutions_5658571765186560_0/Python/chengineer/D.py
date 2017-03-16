import sys

def answer(x, r, c):
    if r * c % x != 0:
        # takes care of x = 1 and x = 2 cases
        return 'RICHARD'
    elif x == 3:
        if (r == 1) ^ (c == 1):
            return 'RICHARD'
        elif (r == 2) ^ (c == 2):
            return 'GABRIEL'
        elif (r == 3) and (c == 3):
            return 'GABRIEL'
        else:
            # (r == 4) ^ (c == 4)
            return 'GABRIEL'
    elif x == 4:
        if (r == 1) ^ (c == 1):
            return 'RICHARD'
        elif (r == 2) and (c == 2):
            return 'RICHARD'
        elif (r == 2) ^ (c == 2):
            return 'RICHARD'
        elif (r == 3) ^ (c == 3):
            return 'GABRIEL'
        else:
            # (r == 4) and (c == 4)
            return 'GABRIEL'
    else:
        return 'GABRIEL'

if __name__ == '__main__':
    f = sys.stdin
    fn = sys.argv[1]
    f = open(fn)
    if len(sys.argv) == 3:
        output = open(sys.argv[2], 'w')

    t = int(f.readline())
    for _t in xrange(t):
        [x, r, c] = map(int, f.readline().split())
        ans = answer(x, r, c)
        if len(sys.argv) == 3:
            output.write('Case #%d: %s' % (_t+1, ans) + '\n')
        print 'Case #%d: %s' % (_t+1, ans)
