from itertools import chain, combinations


def powerset(iterable):
    xs = list(iterable)
    return chain.from_iterable(combinations(xs, n) for n in range(len(xs) + 1))


def valid(originals, pairs):
    first_origs = set()
    second_origs = set()
    for first, second in originals:
        first_origs.add(first)
        second_origs.add(second)
    for first, second in pairs:
        if first not in first_origs or second not in second_origs:
            return False
    return True


cases = int(raw_input())

for ctr in xrange(cases):
    num_pairs = int(raw_input())
    pairs = []
    for x in xrange(num_pairs):
        pairs.append(raw_input().split(" "))

    max_fakes = 0
    for originals in powerset(pairs):
        if valid(originals, pairs):
            max_fakes = max(max_fakes, len(pairs) - len(originals))

    print "Case #%d: %s" % (ctr + 1, max_fakes)
