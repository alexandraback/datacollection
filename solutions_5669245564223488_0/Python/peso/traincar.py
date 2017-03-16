import sys
import string
from sys import stderr
from math import factorial

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            print >>stderr, 'Case #{0}'.format(x+1)
            N = int(f.readline())
            c = f.readline().split()
            
            MOD = 1000000007
            
            def countem(allCars):
                print >>stderr, allCars
                letters = set(''.join(allCars))
                sum = 1
                
                prev=dict()
                next=dict()
                inPerm=dict()
                
                for l in letters:
                    prev[l] = None
                    next[l] = None
                    inPerm[l] = 1
                    cars = [car for car in allCars if l in car]
                    #otherCarsLetters = set(''.join([car 
                    #    for car in allCars if car not in cars]))
                        
                    heads = [car for car in cars if car[0] != l]
                    if len(heads) > 1: return 0
                    if len(heads) == 1:
                        prevL = heads[0][0]
                        assert prevL != l
                        prev[l] = prevL
                        
                    tails = [car for car in cars if car[-1] != l]
                    if len(tails) > 1: return 0
                    if len(tails) == 1:
                        nextL = tails[-1][-1]
                        assert nextL != l
                        next[l] = nextL
                        
                    print >>stderr, ' {0} {1} cars ({2}h {3}t)'.format(
                        l, len(cars), len(heads), len(tails))
                    inCars = [car for car in cars if car not in heads and car not in tails]
                    #print >>stderr, ' heads=', heads
                    #print >>stderr, ' tails=', tails
                    #print >>stderr, ' inCars=', inCars
                    inPerm[l] = factorial(len(inCars)) % MOD
                    
                seen = set([])
                train = []
                for l in letters:
                    if l in seen: continue
                    a = l
                    pr = [a]
                    while prev[a] is not None:
                        p=prev[a]
                        if next[p] != a: 
                            print >>stderr, prev[a], '<-', a, '!=', p, '->', next[p]
                            return 0
                        a = p
                        if a in pr:
                            return 0
                        pr.append(a)
                    seen.add(a)
                    mul = inPerm[a]
                    t = [a]
                    while next[a] is not None:
                        n = next[a]
                        if n in t:
                            return 0
                        if prev[n] != a: 
                            print >>stderr, a, '->', next[a], '!=', prev[n], '<-', n
                            return 0
                        a = n
                        seen.add(a)
                        mul = (mul * inPerm[a]) % MOD
                        t.append(a)
                    train.append(mul)
                    print >> stderr, t, '=', mul
                    
                mul = factorial(len(train)) % MOD
                for m in train:
                    mul = (mul * m) % MOD
                    
                return mul
                
                
                    
                    
            outf.write('Case #{0}: {1}'.format(x+1, countem(c)))
            outf.write('\n')
