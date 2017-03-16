import sys
import itertools
import collections
import random
def foo():
    return collections.Counter()

facts = [1]
for i in xrange(1, 50):
    facts.append(facts[-1] * i)

def multinomial(prob):
    z = collections.Counter(prob)
    N = len(prob)
    out = facts[N]
    for v in z.itervalues():
        out /= facts[v]
    return out

def solve(N, M, problems):
    poss = list(itertools.combinations_with_replacement(range(2, M+1), N))
    multiplier = [multinomial(x) for x in poss]
    S = sum(multiplier)
    multiplier = [f * 1.0 / S for f in multiplier]
    print >>sys.stderr, "MULTI"
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
    #summas = dict((k, 1.0/sum(counts[k].itervalues())) for k in counts)
    PP = pow(0.5, N)
    print >>sys.stderr, "GENED"
    
    for problem in problems:
        cando = set(range(len(poss)))
        thecount = [1] * len(poss)
        for z in problem:
            #newcount = collections.Counter()
            oh = counts[z]
            #assert cando
            #POO = 1.0 / sum(v for k,v in oh.iteritems() if k in cando)
            ncando = []
            for idx in cando:
                if idx not in oh:
                    ncando.append(idx)
                    continue
                thecount[idx] *= oh[idx]
            for t in ncando:
                cando.remove(t)
        best = []
        bestsc = -1.0
        for idx in cando:
            v = thecount[idx]
            if v > bestsc:
                best = [idx]
                bestsc = v
            elif v == bestsc:
                best.append(idx)
        print ''.join(str(i) for i in poss[random.choice(best)])

def main():
    T = int(sys.stdin.readline())
    for cn in range(1, T+1):
        R, N, M, K = [int(s) for s in sys.stdin.readline().strip().split()]
        problems = [[int(s) for s in sys.stdin.readline().strip().split()] for q in xrange(R)]
        print "Case #%d:" % (cn)
        solve(N, M, problems)
if __name__ == '__main__':
    main()
        
