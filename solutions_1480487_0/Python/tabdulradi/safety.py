from math import ceil

def testcase_handler(line):
    line = line.split()
    n = float(line[0])
    ss = [float(s) for s in line[1:]]
    x = sum(ss)
    return ' '.join([str((((2*x)/n - s)/x)*100) for s in ss])

def file_handler(f):
    for i in range(int(f.readline())):
        yield "Case #%s: %s" % (i+1, testcase_handler(f.readline()))

import sys
for line in file_handler(sys.stdin):
    print line
