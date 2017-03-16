#!/usr/bin/python

import sys, datetime

def solve(k, c, s):
    n = 1
    checked = []
    while n <= k:
        a = n
        m = n + 1
        i = 2
        while m <= k and i <= c:
            a = (a-1)*k + m
            m += 1
            i += 1
        checked.append(a)
        n = m
    if len(checked) <= s:
        return ' '.join(map(str, checked))
    else:
        return 'IMPOSSIBLE'
    
def parse(input_file):
    k, c, s = map(int, input_file.readline().strip().split())
    return (k, c, s)

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
