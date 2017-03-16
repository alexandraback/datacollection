#!/usr/bin/python

import sys, datetime

def solve(s):
    t = s[0]
    for x in s[1:]:
        if x >= t[0]:
            t = x + t
        else:
            t = t + x
    return t

def parse(input_file):
    s = input_file.readline().strip()
    return (s, )

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
