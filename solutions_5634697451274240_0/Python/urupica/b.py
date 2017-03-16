#!/usr/bin/python

import sys, datetime

def flip(s, k):
    s[:k] = s[:k][::-1]
    for i in xrange(k):
        s[i] = (s[i] + 1)%2

def strip(s):
    while s and s[-1] == 1:
        s.pop()

def solve(s):
    s = map(lambda x:1 if x == '+' else 0, s)
    strip(s)
    n = 0
    while s and 0 in s:
        n += 1
        if s[0] == 1:
            i = 0
            while i < len(s) and s[i] == 1:
                i += 1
            flip(s, i)
        else:
            flip(s, len(s))
            strip(s)
    return n


def parse(input_file):
    s = input_file.readline().strip()
    return (s,)

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
