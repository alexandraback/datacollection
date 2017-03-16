

def minimize(aa):
    return ''.join([a if a != '?' else '0' for a in aa])


def maximize(aa):
    return ''.join([a if a != '?' else '9' for a in aa])


def brute_force(aa, bb):
    if len(aa) == 0:
        yield ('', '')
        return
    if aa[0] == '?' and bb[0] == '?':
        for a, b in brute_force(aa[1:], bb[1:]):
            yield '0' + a, '0' + b
        yield '1' + minimize(aa[1:]), '0' + maximize(bb[1:])
        yield '0' + maximize(aa[1:]), '1' + minimize(bb[1:])
    elif aa[0] == bb[0]:
        for a, b in brute_force(aa[1:], bb[1:]):
            yield aa[0] + a, bb[0] + b
    elif aa[0] == '?' and bb[0] != '?':
        same = bb[0]
        for a, b in brute_force(aa[1:], bb[1:]):
            yield same + a, same + b
        if bb[0] != '0':
            lower = str(int(bb[0]) - 1)
            yield lower + maximize(aa[1:]), bb[0] + minimize(bb[1:])
        if bb[0] != '9':
            higher = str(int(bb[0]) + 1)
            yield higher + minimize(aa[1:]), bb[0] + maximize(bb[1:])
    elif aa[0] != '?' and bb[0] == '?':
        same = aa[0]
        for a, b in brute_force(aa[1:], bb[1:]):
            yield same + a, same + b
        if aa[0] != '0':
            lower = str(int(aa[0]) - 1)
            yield aa[0] + minimize(aa[1:]), lower + maximize(bb[1:])
        if aa[0] != '9':
            higher = str(int(aa[0]) + 1)
            yield aa[0] + maximize(aa[1:]), higher + minimize(bb[1:])
    elif int(aa[0]) > int(bb[0]):
        yield minimize(aa), maximize(bb)
    elif int(aa[0]) < int(bb[0]):
        yield maximize(aa), minimize(bb)
    else:
        raise Exception("IMPOSSIBLE!")


def difference(a, b):
    ia = int(a)
    ib = int(b)
    return abs(ia - ib)

cases = int(raw_input())

for ctr in xrange(cases):
    ss = raw_input()
    split = ss.split(" ")
    aa, bb = split[0], split[1]
    best = None
    for a, b in brute_force(aa, bb):
        diff = difference(a, b)
        better = False
        if best is None:
            better = True
        elif diff < best[2]:
            better = True
        elif diff == best[2]:
            if a < best[0]:
                better = True
            elif a == best[0] and b < best[1]:
                better = True
        if better:
            best = a, b, diff
    print "Case #%d: %s %s" % (ctr + 1, best[0], best[1])
