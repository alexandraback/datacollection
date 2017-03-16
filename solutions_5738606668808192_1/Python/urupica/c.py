#!/usr/bin/python

import sys, datetime

def solve(n, j):
    b = 2**(n-1) + 1
    sol = []
    primes = (2, 3, 5, 7)
    while len(sol) < j:
        s = bin(b)[2:]
        valid = True
        divisors = []
        for m in xrange(2, 11):
            k = int(s, m)
            found = False
            for p in primes:
                if k % p == 0:
                    divisors.append(p)
                    found = True
                    break
            if not found:
                valid = False
                break
        if valid:
            sol.append([s] + divisors)
        b += 2
    return ''.join('\n' + ' '.join(map(str, x)) for x in sol)

def parse(input_file):
    n, j = map(int, input_file.readline().strip().split())
    return (n, j)

def main():
    start = datetime.datetime.now()
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[2], "w") if len(sys.argv) > 2 else None
    print "Writing to %s" % sys.argv[2] if output_file else "No output file"
    test_cases = int(input_file.readline().strip())
    print "Test cases:",test_cases
    print '-----------------'
    for tc in xrange(1, test_cases + 1):
        output = "Case #%d:%s" % (tc, solve(*parse(input_file)))
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
