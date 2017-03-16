import sys

_filename = sys.argv[1]
_in = open(_filename)
def ints():
    return map(int, _in.readline().split())
def raw():
    return _in.readline().rstrip('\n')
raw_input = raw # we all forget sometimes

def seq2int(seq, base):
    ret = 0
    for s in seq:
        ret *= base
        ret += s
    return ret+1

def solve(K, C, S):
    if S * C < K:
        return "IMPOSSIBLE"
    L = (K-1) / C + 1 # ceil K/C
    #ans = [seq2int([i] * K, K) for i in range(K)] # works for S == k
    ans = []
    for i in range(L):
        seq = [min(C*i + j, K-1) for j in range(C)]
        ans.append(seq2int(seq, K))
    return ' '.join(map(str, ans))

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        K, C, S = ints()
        print "Case #{}: {}".format(case_num, solve(K, C, S))
