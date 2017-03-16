import sys

def cnt(N):
    if N < 10:
        return N
    digits = len(str(N))
    hd = digits // 2
    if all(c == '0' for c in str(N)[hd:]):
        return cnt(N - 1) + 1

    base = int('9'*(digits-1))
    r = cnt(base)
    target_str = '1' + '0'*(digits - hd - 1) + str(N)[:hd][::-1]
    r += int(target_str) - base
    if target_str[::-1] != target_str:
        target_str = target_str[::-1]
        r += 1
    base = int(target_str)
    return r + (N - base)

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

for t in xrange(pop_int()):
    N = pop_int()
    print 'Case #{}: {}'.format(t+1, cnt(N))
