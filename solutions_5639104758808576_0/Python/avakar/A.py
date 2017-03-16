import sys

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

def pop_str():
    return input.pop(0)

for t in xrange(pop_int()):
    s_max = pop_int()
    s_levels = [int(c) for c in pop_str()]

    covered = 0
    needed = 0
    for i, l in enumerate(s_levels):
        if not l:
            continue
        if covered < i:
            needed += i - covered
            covered = i
        covered += l

    print 'Case #{}: {}'.format(t+1, needed)
