def check(x):
    for c in '0123456789':
        if c not in x:
            return False
    return True

def solve_slow(N):
    if N == 0:
        return 'INSOMNIA'
    seen = str(N)
    i = 1
    while not check(seen):
        i += 1
        seen += str(i*N)
    return i*N



def main():
    T = int(raw_input())
    for i in xrange(T):
        N = int(raw_input())
        print 'Case #%d:' % (i+1), solve_slow(N)

main()
