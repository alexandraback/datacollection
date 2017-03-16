

from itertools import combinations, imap

def all_combs(st):
    for i in xrange(len(st)):
        for pm in combinations(st, i + 1):
            yield pm

def find_sum(sm, st):

    for c in all_combs(st):
        if sum(c) == sm:
            return c

    return None


st = map(int, "120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600".split(' '))

def solve():
    st = map(int, raw_input().split(' ')[1:])

    for c in all_combs(st):
        assert len(c) < 3
        #print 'trying ', c

        new_st = list(st)
        for i in c: new_st.remove(i)

    #    print new_st, sum(c)

        s = find_sum(sum(c), new_st)

        if s:
            return c, s

t = int(raw_input())

for i in xrange(t):
    a, b = solve()

    print 'Case #%i:' % (i + 1)
    print ' '.join(imap(str, a))
    print ' '.join(imap(str, b))
