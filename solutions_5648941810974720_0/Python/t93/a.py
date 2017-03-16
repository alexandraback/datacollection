digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


l1 = { "U": 4, "W": 2, "Z": 0, "G": 8, "X": 6 }
l2 = { "F": 5, "H": 3, "O": 1, "S": 7 }
l3 = { "I": 9 }

def main():
    t = int(raw_input())
    for ti in xrange(t):
        inp = raw_input()
        counts = {}
        ans = []
        for c in inp:
            counts[c] = counts.get(c, 0) + 1
        #print counts
        for l in l1, l2, l3:
            for k, v in l.iteritems():
                n = counts.get(k, 0)
                #print "found %d of %s (%s)" % (n, k, digits[v])
                if n > 0:
                    ans.extend([v] * n)
                    for c in digits[v]:
                        counts[c] -= n
                #print counts
        #print counts
        print "Case #%d: %s" % (ti + 1, ''.join(map(str, sorted(ans))))

main()
