from fractions import Fraction

pow2s = [ 2**i for i in xrange(1000) ]
pow2s_set = set(pow2s)
pow2s_inverses = [ Fraction(1, i) for i in pow2s ]

def findMinGeneration(fraction):
    fraction = Fraction(fraction)
    if fraction.denominator not in pow2s_set:
        return 'impossible'
    for i, num in enumerate(pow2s_inverses):
        if num <= fraction:
            return i
    assert False

numCases = input()
for caseNum in xrange(numCases):
    print 'Case #{0}: {1}'.format(caseNum+1, findMinGeneration(raw_input()))

