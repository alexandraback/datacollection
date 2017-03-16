import itertools

def main():
    t = int(raw_input())
    for i in xrange(t):
        s = raw_input()
        g = list(itertools.groupby(s))
        if (g[-1][0] == '+'):
            g = g[:-1]
        print "Case #%d: %s" % (i + 1, len(g))

if __name__ == "__main__":
    main()
