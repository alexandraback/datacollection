import sys
import itertools
import collections

def foo():
    return collections.Counter()

def solve(N, M, problems):
    poss = list(itertools.combinations_with_replacement(range(2, M+1), N))
    counts = collections.defaultdict(foo)
    for idx, listing in enumerate(poss):
        mycount = collections.Counter([1])
        for thing in listing:
            newcount = collections.Counter()
            for k, v in mycount.iteritems():
                newcount[k] += v
                newcount[k*thing] += v
            mycount = newcount
        for k, v in mycount.iteritems():
            counts[k][idx] += v
    PP = pow(0.5, N)
    for problem in problems:
        thecount = [1.0] * len(poss)
        for z in problem:
            #newcount = collections.Counter()
            oh = counts[z]
            for idx in range(len(poss)):
                thecount[idx] *= oh[idx] * PP
        best = 0
        bestsc = 0
        for idx, v in enumerate(thecount):
            if v > bestsc:
                best = idx
                bestsc = v
        print ''.join(str(i) for i in poss[best])

def main():
    T = int(sys.stdin.readline())
    for cn in range(1, T+1):
        R, N, M, K = [int(s) for s in sys.stdin.readline().strip().split()]
        problems = [[int(s) for s in sys.stdin.readline().strip().split()] for q in xrange(R)]
        print "Case #%d:" % (cn)
        solve(N, M, problems)
if __name__ == '__main__':
    main()
        
