import sys
import itertools

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            c,d,v = map(int, f.readline().split())
            denoms = map(int, f.readline().split())
            yield case, (c,d,v, denoms)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def problem(c,d,v, denoms):
    denoms = sorted(denoms)
    print c,d,v, denoms
    subs = findsubsets(denoms)
    can_make = set([])
    for sub in subs:
        if sub:
            can_make.add(reduce(lambda x, y : x+y, sub))
    print "can", can_make
    cannot_make = []
    for i in range(1, v+1):
        if i not in can_make:
            cannot_make.append(i)
    print "cannot", cannot_make
    if not cannot_make:
        return 0
    if len(cannot_make) == 1:
        return 1
    difs = {}
    for i in cannot_make:
        for j in can_make:
            if i > j:
                if i -j in denoms:
                    continue
                if i not in difs:
                    difs[i] = set([i-j])
                else:
                    difs[i].add(i-j)
    count = 1
    if not difs.values():
        return 1
    inter = difs.values()[0]
    for i in difs.values():
        inter = inter.intersection(i)
        if not inter:
            count += 1
            inter = set(range(v+1))
    return count

def findsubsets(s):
    alsub = set([])
    for i in range(len(s)+1):
        for x in itertools.combinations(s,i):
            alsub.add(x)
    return alsub

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

