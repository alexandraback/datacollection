import string

MOD = 1000000007


class NoSolution(ValueError):
    pass


def ends(t):
    s, cnt = t
    return s[0], s[-1]


def filter_mg_tripple(tr, c):
    left, mid, right = [], [], []
    other = []

    for t in tr:
        l, r = ends(t)
        if (l, r) == (c, c):
            mid.append(t)
        elif l == c:
            right.append(t)
        elif r == c:
            left.append(t)
        else:
            other.append(t)

    return left, mid, right, other


def mod_fact(n):
    if n == 0:
        return 1
    else:
        return (n * mod_fact(n - 1)) % MOD


def mod_mult(lst):
    r = 1
    for n in lst:
        r = (r * n) % MOD
    return r


def combine_anyway(trains):
    s = ''.join(s for s, _ in trains)
    cnt = mod_mult([mod_fact(len(trains)),
                    mod_mult(c for _, c in trains)])
    #print 'combined', trains, repr(s), cnt
    return s, cnt


def combine_in_ord(t1, t2):
    s1, c1 = t1
    s2, c2 = t2
    return s1 + s2, mod_mult([c1, c2])

def split_same_char(todo):
    def rec(s):
        if not s:
            return []

        for i in range(1, len(s)):
            if s[0] != s[i]:
                return [''.join(s[0:i])] + rec(s[i:])

        return [''.join(s)]

    return rec(list(todo))


def invalid_train(s):
    chars_seq = split_same_char(s)
    chars = [s[0] for s in chars_seq]
    seen = set()
    for c in chars:
        if c in seen:
            return True
        seen.add(c)
    return False

def join_tripple(left, mid, right):
    if len(left) > 1 or len(right) > 1:
        raise NoSolution()

    result = combine_anyway(mid)
    if left:
        result = combine_in_ord(left[0], result)
    if right:
        result = combine_in_ord(result, right[0])

    return result


def solve_trains(trains):
    trains = [(s, 1) for s in trains]
    for c in string.lowercase:
        left, mid, right, trains = filter_mg_tripple(trains, c)
        if left or mid or right:
            print left, mid, right, trains
            trains.append(join_tripple(left, mid, right))

    result, cnt = combine_anyway(trains)

    print 'Result:', result
    if invalid_train(result):
        raise NoSolution()

    return cnt

def answer(trains):
    try:
        return str(solve_trains(trains))
    except NoSolution:
        return '0'

import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            n = int(inf.readline())
            words = inf.readline().split()
            outf.write('Case #{}: {}\n'.format(t,answer(words)))