#!/usr/bin/python

import sys, datetime

def solve(n, f):
    f = map(lambda k:k-1, f)
    pairs = []
    for i, x in enumerate(f):
        if f[x] == i:
            p = (min(i,x), max(i,x))
            if p not in pairs:
                pairs.append(p)
    best = 0
    for k in xrange(n):
        lst = [k]
        c = k
        while f[c] not in lst:
            lst.append(f[c])
            c = f[c]
        if f[c] == lst[0]:
            best = max(best, len(lst))
    best_pairs = [0]*len(pairs)
    for i, (a, b) in enumerate(pairs):
        best1 = best2 = 1 
        for k in xrange(n):
            if k in [a,b]:
                continue
            checked = {a,b,k}
            c = k
            while f[c] not in checked:
                checked.add(f[c])
                c = f[c]
            if f[c] == a:
                best1 = max(best1, len(checked) - 1)
            elif f[c] == b:
                best2 = max(best2, len(checked) - 1)
        best_pairs[i] = best1 + best2
    best = max(best, sum(best_pairs))
    return best

def parse(input_file):
    n = int(input_file.readline().strip())
    f = map(int, input_file.readline().strip().split())
    return (n, f)

def main():
    start = datetime.datetime.now()
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[2], "w") if len(sys.argv) > 2 else None
    print "Writing to %s" % sys.argv[2] if output_file else "No output file"
    test_cases = int(input_file.readline().strip())
    print "Test cases:",test_cases
    print '-----------------'
    for tc in xrange(1, test_cases + 1):
        output = "Case #%d: %s" % (tc, solve(*parse(input_file)))
        print output
        if output_file:
            output_file.write(output + "\n")
    print '-----------------'
    print "Written to %s" % sys.argv[2] if output_file else "No output file"
    print 'Elapsed time: %s' % (datetime.datetime.now() - start)
    input_file.close()
    if output_file:
        output_file.close()

if __name__ == "__main__":
    main()
