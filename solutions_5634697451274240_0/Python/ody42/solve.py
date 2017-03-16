import sys

def fast(S):
    changes = 0

    if not S:
        return 0

    prev = S[0]
    for c in S[1:]:
        if c != prev:
            changes += 1
            prev = c
        
    if (len(S) > 1 and c == '-') or S == '-':
        changes += 1

    return changes
            
def solve(S):
    return fast(S)

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        S = sys.stdin.readline().strip()
        SOL = solve(S)
        print 'Case #%s: %s' % (i+1, SOL)

if __name__ == '__main__':
    main()
