# -*- coding:utf-8 -*-
import os
import sys
import itertools

def solve(matrix, n, m):
    """Juedge possibility of lawnmowing."""
    h_max = [max(matrix[i*m:i*m+m]) for i in xrange(n)]
    v_max = [max(matrix[j::m]) for j in xrange(m)]
    
    #print 'H:', h_max
    #print 'V:', v_max

    any_violation = any((matrix[i+j*m] < h_max[j] and matrix[i+j*m] < v_max[i]
        for i in xrange(m) for j in xrange(n)))
    return 'NO' if any_violation else 'YES'

    for i in xrange(m):
        for j in xrange(n):
            e = matrix[i + j*m]
            if e < h_max[i] and e < v_max[j]:
                return 'NO'
    return 'YES'

if __name__ == '__main__':
    in_file = sys.argv[1]
    out_file = os.path.splitext(in_file)[0] + '.out'
    #print out_file
    output = open(out_file, 'w')

    with open(in_file) as test:
        rounds = int(test.next())
        #print rounds, 'rounds'

        for i in xrange(rounds):
            n, m = map(int, test.next().split())
            #print n, 'x', m

            lines = []
            for j in xrange(n):
                lines.append(map(int, test.next().split()))
            #print lines
            matrix = list(itertools.chain(*lines))

            res = solve(matrix, n, m)
            #print res
            output.write("Case #%d: %s\n" % (i+1, res))
            #print

    output.close()
