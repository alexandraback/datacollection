from fractions import Fraction
import numpy as np

def parse_file(fnIn, fnOut):
    with open(fnOut, 'w') as fOut:
        with open(fnIn, 'rU') as fIn:
            T = int(fIn.readline())

            for n in xrange(T):
                s = fIn.readline().strip()

                N = num_gens(s)

                fOut.write('Case #%d: %s\n'%(n + 1, N))


def num_gens(s):
    frac = Fraction(s)

    lgdenom = np.log2(frac.denominator)
    ilgdenom = int(lgdenom)

    if lgdenom != ilgdenom:
        return 'impossible'

    return ilgdenom - int(np.log2(frac.numerator))
