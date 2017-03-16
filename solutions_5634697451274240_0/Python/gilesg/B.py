import sys

_filename = sys.argv[1]
_in = open(_filename)
def ints():
    return map(int, _in.readline().split())
def raw():
    return _in.readline().rstrip('\n')
raw_input = raw # we all forget sometimes

def solve(S):
    first = S[0]
    # count number of blocks
    blocks = 0
    curr = None
    for c in S:
        if curr != c:
            blocks += 1
            curr = c
    if first == '+':
        return blocks / 2 * 2
    else:
        assert first == '-'
        return (blocks + 1) / 2 * 2 - 1

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        S = raw()
        print "Case #{}: {}".format(case_num, solve(S))
