
def is_consonant(l):
    return l not in 'aeiou'


def solve(name, n):
    l = len(name)
    start_pos = []
    count = 0
    for i in range(n):
        if is_consonant(name[i]):
            count += 1
    for i in range(l-n+1):
        # print count
        if count == n:
            start_pos.append(i)
        if is_consonant(name[i]):
            count -= 1
        if i+n < l and is_consonant(name[i+n]):
            count += 1
    # print start_pos
    value = 0
    for i, p in enumerate(start_pos):
        if i > 0:
            pp = start_pos[i-1]
            n_left = p - pp
        else:
            n_left = p + 1
        n_right = l - p - n + 1
        # print n_left, n_right
        value += n_left * n_right
    return value


##############################################################################

def read_ints(f):
    s = f.readline()
    return [int(w) for w in s.strip().split()]


from sys import argv

in_fn = argv[1]
out_fn = len(argv) > 2 and argv[2] or in_fn + '.out'

in_f = open(in_fn)
out_f = open(out_fn, 'w')

T = int(in_f.readline().strip())

for i_t in range(T):
    name, n = in_f.readline().strip().split()
    n = int(n)
    # cache = {}
    res = solve(name, n)
    out_ln =  'Case #%d: %s' % (i_t+1, res)
    print >> out_f, out_ln
    print out_ln



