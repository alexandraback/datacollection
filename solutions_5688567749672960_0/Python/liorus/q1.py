__author__ = 'Lior'

def rev(n):
    return int(str(n)[::-1])

M = {}
SEEN = set()

def solve(start, N):
    if start in SEEN:
        return None
    SEEN.add(start)
    if start in M:
        return M[start]
    if start > N:
        return None
    if start == N:
        return 1
    r = rev(start)
    if r <= start:
        b = solve(start+1, N)
        if b is None:
            return None
        M[start] = b + 1
        return M[start]
    a = solve(rev(start), N)
    b = solve(start+1, N)
    if a is None and b is None:
        M[start] = None
        return None
    if a is None:
        M[start] = b+1
        return b+1
    if b is None:
        M[start] = a+1
        return a+1
    M[start] = min(a, b) + 1
    return M[start]

def solve2(N):
    BIG_NUMBER = N+1
    for i in xrange(N, 0, -1):
        if i == N:
            M[i] = 1
            continue
        a = M.get(rev(i), BIG_NUMBER) + 1
        b = M[i+1] + 1
        M[i] = min(a, b)
    return M[1]


def process_files(in_file, out_file):
    num_of_test_cases = int(in_file.next().strip())
    for i, test_number in enumerate(xrange(num_of_test_cases)):
        M.clear()
        SEEN.clear()
        N = int(in_file.next().strip())
        print 'test %d: %d:' %  (i, N)

        result = solve2(N)
        out_file.write('Case #%d: %s\n' % (test_number+1, result))



if __name__ == '__main__':
    import sys, os
    in_file = sys.argv[1]
    out_file = in_file.replace('.in', '.out')
    with open(in_file, 'rb') as in_file:
        with open(out_file, 'wb') as out_file:
            process_files(in_file, out_file)
