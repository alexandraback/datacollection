from collections import OrderedDict

def parse_file(fnIn, fnOut):
    with open(fnOut, 'w') as fOut:
        with open(fnIn, 'rU') as fIn:
            T = int(fIn.readline())

            for n in xrange(T):
                fIn.readline() # discard
                trains = fIn.readline().strip().split()

                N = num_perms(trains)

                s = 'Case #%d: %d\n'%(n + 1, N%1000000007)
                fOut.write(s)
                print s


def num_perms(trains):
    # preprocess: compress
    trains = map(compress, trains)

    n = 0

    stack = [(t, [v for j,v in enumerate(trains) if j != i])
            for i,t in enumerate(trains)]

    while stack:
        current,others = stack.pop()

        # if no others, we've used them all and so this should be valid
        if not others:
            n += 1
            continue

        # valid if any letter in other is either not in current or is at the
        # end of current and the start of t
        end = current[-1]

        def is_valid(train):
            if train[0] == end:
                train = train.lstrip(end)

            return all(c not in current for c in train)

        valid = filter(is_valid, others)

        extras = []

        for t in valid:
            new = current + t

            newOthers = []

            for i,other in enumerate(others):
                if other != t or others.index(other) != i:
                    newOthers.append(other)

            extras.append((new, newOthers))

        stack.extend(extras)

    return n


def compress(s):
    return ''.join(OrderedDict(((c,None) for c in s)).keys())
