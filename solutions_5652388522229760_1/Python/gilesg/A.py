import sys

_filename = sys.argv[1]
_in = open(_filename)
def ints():
    return map(int, _in.readline().split())
def raw():
    return _in.readline().rstrip('\n')
raw_input = raw # we all forget sometimes

def solve(N):
    if N == 0:
        return "INSOMNIA"
    M = 0
    seen = set()
    while len(seen) < 10:
        M += N
        seen.update(list(str(M)))
    return M

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        N, = ints()
        print "Case #{}: {}".format(case_num, solve(N))
