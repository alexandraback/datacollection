import itertools

def testcase_handler(line):
    numbers = [int(n) for n in line.split()[1:]]
    results = {}
    for m in range(1,  len(numbers)):
        for lst in itertools.combinations(numbers, m):
            result = sum(lst)
            if result in results:
                return '\n%s\n%s' % (
                                    ' '.join([str(n) for n in results[result]]), 
                                    ' '.join([str(n) for n in lst])
                                )
                
            results[result] = lst
    return 'Impossible'

def file_handler(f):
    for i in range(int(f.readline())):
        yield "Case #%s: %s" % (i+1, testcase_handler(f.readline()))

import sys
for line in file_handler(sys.stdin):
    print line
