import itertools

DEBUG = True
DEBUG = False


def solve(c, d, v, existing):
    existing = set(existing)
    sorted_existing = sorted(existing)

    if v == 1:
        return 0 if 1 in existing else 1
    if v == 2 and c == 1:
        return len(set([1,2]).difference(existing))
    if v == 2 and c > 1:
        return 0 if 1 in existing else 1

    assert v > 2

    if DEBUG:
        print 'start', c, v, existing

    denominations_added = None

    if c == 1:
        denominations_added = int(1 not in existing) + int(2 not in existing)
        current_v = 1 + 2
        denoms = [1,2]
        if current_v >= v:
            return denominations_added

        for x in sorted_existing:
            if current_v >= v:
                return denominations_added

            if x == 1 or x == 2:
                continue

            while x > current_v + 1:
                denominations_added += 1
                denoms.append(current_v + 1)
                current_v = 2*current_v + 1
                if current_v >= v:
                    return denominations_added

            assert x not in denoms
            denoms.append(x)
            current_v += x

        while v > current_v:
            denominations_added += 1
            denoms.append(current_v + 1)
            current_v = 2*current_v + 1
            if current_v >= v:
                return denominations_added

        assert len(denoms) == denominations_added + len(existing), (denoms, denominations_added, existing)
        assert sum(denoms) == current_v, (denoms, current_v, existing)
        if DEBUG:
            print 'finish', denominations_added, denoms

    return denominations_added


t = input()
for i in range(t):
    c, d, v = map(int, raw_input().split(' '))
    existing = map(int, raw_input().split(' '))
    print 'Case #%d: %s' % (i + 1, solve(c, d, v, existing))
