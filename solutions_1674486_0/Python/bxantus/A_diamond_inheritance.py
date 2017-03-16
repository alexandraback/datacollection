
def has_diamond(inh_map, N):
    def add_bases(bases, c):
        parents = inh_map[c]
        for base in parents:
            if base in bases:
                return True #diamond it is
            else:
                bases.add(base)
                if add_bases(bases, base):
                    return True
        return False

    # check each class
    for c in xrange(1, N + 1):
        bases = set()
        if add_bases(bases, c):
            return True
    return False

def main():
    tc = 'A-small-attempt0'
    f = open("%s.in" % (tc))
    outf = open("%s.out" % (tc), "w")

    T = int(f.readline())

    RES_MAP = { True : "Yes", False: "No" }
    for i in xrange(1, T + 1):
        N = int(f.readline())
        inh = {}
        for j in xrange(1, N + 1):
            bases = [int(x) for x in f.readline().split()][1:]
            inh[j] = bases
        print inh
        result = has_diamond(inh, N)
        print i, result
        outf.write("Case #%d: %s\n" % (i, RES_MAP[result]))
    f.close()
    outf.close()

if __name__ == '__main__':
    main()
