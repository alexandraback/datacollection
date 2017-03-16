import sys


def solve(C, J):
    LEN = len(C)
    assert len(C) == len(J)
    
    maybe_cj = []
    
    for i in xrange(LEN):
        if C[i] != '?' and J[i] != '?':
            x = int(C[i])
            y = int(J[i])
            maybe_cj.append([(x, y)])
            
            continue
        elif C[i] == '?' and J[i] == '?':
            maybe_cj.append([
                (0, 0),
                (0, 1),
                (1, 0),
                (9, 0),
                (0, 9),
            ])            
        elif C[i] != '?':
            x = int(C[i])
            vals = [(x, (x+off) % 10) for off in [-1, 0, 1]]
            vals.extend([(x, 0), (x,9)])
            maybe_cj.append(vals)
        elif J[i] != '?':
            y = int(J[i])
            vals = [((y+off) % 10, y) for off in [-1, 0, 1]]
            vals.extend([(0,y), (9,y)])
            maybe_cj.append(vals)
        
    stack = [(0, 0)]

    for i in xrange(LEN):
        dec = 10 ** (LEN-i-1)
        new_stack = []
        for s in stack:
            csum, jsum = s
            for (cx, jx) in maybe_cj[i]:
                new_stack.append((csum + cx * dec, jsum + jx * dec))

        stack = new_stack


    ans = min(stack, key=lambda (csum, jsum): ((abs(csum-jsum), csum, jsum)))

    return str(ans[0]).rjust(LEN, '0'), str(ans[1]).rjust(LEN, '0')
            
            
            
            
            
def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        C, J = sys.stdin.readline().strip().split()
        c, j = solve(C, J)
        print 'Case #%s: %s %s' % (i+1, c, j)

if __name__ == '__main__':
    main()
