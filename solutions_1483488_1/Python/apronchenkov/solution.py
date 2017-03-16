import sys

def shift(seq, n):
    return seq[n:]+seq[:n]

normalize_cache = dict()
def normalize(string):
    result = normalize_cache.get(string)
    if result:
        return result
    formSeq = [ shift(string, n) for n in xrange(len(string)) ]
    result = min(*formSeq)
    for form in formSeq:
        normalize_cache[form] = result
    return result
#    for n in xrange(1, len(result)):
#        result = min(result, shift(string, n))
#    return result
    

def solve(lowerBound, upperBound):
    result = 0
    state = dict()
    for number in xrange(lowerBound, upperBound):
        pivot = normalize(str(number))
        pivotCounter = state.get(pivot, 0)
        state[pivot] = pivotCounter + 1
        result += pivotCounter
    return result
            

numberOfCases = int(sys.stdin.readline())
for case in xrange(numberOfCases):
    tokenSeq = map(int, sys.stdin.readline().strip().split())
    lowerBound = tokenSeq[0]
    upperBound = tokenSeq[1] + 1
    print "Case #%d: %d" % (case + 1, solve(lowerBound, upperBound))
