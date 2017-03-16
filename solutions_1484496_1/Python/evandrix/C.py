import sys
import time
import math

def powerset(seq):
    if len(seq) <= 1:
        yield seq
        yield []
    else:
        for item in powerset(seq[1:]):
            yield [seq[0]]+item
            yield item

if __name__ == "__main__":
    t0 = time.time()
    _i = open("/Users/lwy08/Downloads/C-large.in", "r")
    _o = open("/Users/lwy08/Downloads/C.out", "w")
    T = int(_i.readline())
    for _t in xrange(T):
        line = _i.readline().split()
        N = int(line[0])
        S = map(int, line[1:])

        sums_seen_so_far = {}
        lookup = {}
        for x in powerset(S):
            if sum(x) not in lookup:
                lookup[sum(x)] = [x]
            else:
                lookup[sum(x)].append(x)
                if (len(lookup[sum(x)]) > 1):
                    break

        print "Case #%d:" % (_t + 1)
        found = False
        for i in lookup:
            if len(lookup[i]) > 1:
                found = True
                print ' '.join(map(str, lookup[i][0]))
                print ' '.join(map(str, lookup[i][1]))
                break
        if not found:
            print "Impossible"

    _i.close()
    _o.close()
    #print >> sys.stderr, "%lf seconds" % (time.time() - t0)
      