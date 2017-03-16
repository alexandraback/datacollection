#!/usr/bin/python

import sys, datetime

def solve(b, m):
    if b == 1:
        if m == 1:
            return 'POSSIBLE\n0'
        return 'IMPOSSIBLE'
    if 2**(b - 2) < m:
        return 'IMPOSSIBLE'
    x = 2**(b - 2)
    mat = []
    for i in xrange(b):
        mat.append([1 if j > i else 0 for j in xrange(b)])
    for i in xrange(3, b + 1):
        if x - 2**(b - i) >= m:
            x -= 2**(b - i)
            mat[0][i - 2] = 0
    if x > m:
        mat[0][-1] = 0
    s = 'POSSIBLE'
    for i in xrange(b):
        s += '\n' + ''.join(map(str, mat[i]))
    return s

def parse(input_file):
    b, m = map(int, input_file.readline().strip().split())
    return (b, m)

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
