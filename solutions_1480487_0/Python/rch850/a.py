from copy import copy

def main():
    T = int(raw_input())
    for tid in xrange(T):
        s = [int(x) for x in raw_input().split()]
        N = s.pop(0)
        X = float(sum(s))
        print "Case #%d:" % (tid + 1),
        in_loop = True
        c = [ci for ci in s if (2. * X) / len(s) >= ci]
        for i in xrange(len(s)):
            lenc = len(c)
            c = [ci for ci in c if (X + sum(c)) / len(c) >= ci]
            if lenc == len(c):
                break
        for si in s:
            if (X + sum(c)) / len(c) < si:
                print 0.0,
            else:
                print 100. * max(((X + sum(c)) / float(len(c)) - float(si)) / X, 0.),
        print

main()

