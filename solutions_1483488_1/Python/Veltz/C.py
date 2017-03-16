# import section
import tools.math
import math
import sys

def solve(Input, output):
    # read case number
    T = int(Input.readline())

    # iterate on all cases
    for t in xrange(T):
        # read N, L and H
        values = Input.readline().split(' ')
        A = int(values[0])
        B = int(values[1])

        # reset recycledPairs to zero
        recycledPairs = 0
        for n in xrange(A, B + 1):
            digits = int(math.ceil(math.log10(n + 1)))
            Ms = set()
            m = n
            for shift in xrange(0, digits):
                m = m / 10 + (m % 10) * pow( 10, digits - 1);
                if ((m > n) and ( m <= B)):
                    # add m to the pair set Ms
                    Ms.add(m)
            recycledPairs = recycledPairs + Ms.__len__()
        # output case result
        outputLine = 'Case #' + str(t + 1) + ": " + str(recycledPairs) + '\n';
        output.write(outputLine)