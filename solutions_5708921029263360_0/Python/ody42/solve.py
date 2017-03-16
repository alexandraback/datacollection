import sys
from collections import defaultdict
import random

    # for s in range(1, S+1):
    #     for p in range(1, P+1):
    #         for j in range(1,J+1):
    
def solve(J,P,S,K, reps=1):

    result = None
    max_outfits = 0
    for _ in xrange(reps):
        combinations = defaultdict(int)
        outfits = defaultdict(int)
        
        combs = [(j,p,s) for s in range(1, S+1) for p in range(1,P+1) for j in range(1,J+1)]
        random.shuffle(combs)
        for (j,p,s) in combs:
            if (j,p,s) in outfits:
                continue
            if combinations[j,p,0] == K or combinations[j,0,s] == K or combinations[0,p,s] == K:
                continue
            outfits[j,p,s] = 1
            combinations[j,p,0] += 1
            combinations[j,0,s] += 1
            combinations[0,p,s] += 1

        if len(outfits) > max_outfits:
            max_outfits = len(outfits)
            result = outfits.keys()
    return result
    # S = 10
    # Different outfits: at most 10**3
            
def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        J,P,S,K = map(int, sys.stdin.readline().strip().split())
        reps = 1
        ans1 = solve(J,P,S,K, reps=reps)
        while True:
            reps*= 100
            ans = solve(J,P,S,K, reps=reps)
            if len(ans) == len(ans1):
                break
            ans1 = ans
        
        print 'Case #%s: %s' % (i+1, len(ans))
        for j,p,s in ans:
            print '%s %s %s' % (j, p, s)

if __name__ == '__main__':
    main()
