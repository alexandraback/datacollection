import itertools

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

#def powerset(seq):
#    if len(seq) <= 1:
#        yield seq
#        yield []
#    else:
#        for item in powerset(seq[1:]):
#            yield [seq[0]] + item
#            yield item


def solve(l):
    p = [x for x in powerset(l)]
    p.pop()
    p.sort()

    f = list()

    for i in p:
        f.append(sum(i))

    a = 0
    b = 0
    for i in f:
        a += 1
        b = a
        for j in f[a:]:
            b += 1
            if i == j:
                return p[a - 1], p[b - 1]

    return "Impossible", 0


c = input()
for i in range(c):
    l = [int(x) for x in raw_input().split()]
    l.pop(0)
    v, r = solve(l)
    print "Case #" + str(i + 1) + ": "
    if v == "Impossible":
        print v
    else:
        for o in v:
            print o,
        print ""
        for o in r:
            print o,
        print ""
