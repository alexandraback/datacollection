import sys
import random

def find_divisor(x):
    for i in range(2,1000):
        if x%i == 0:
            return i
    
    return x

def find_proof(cand):
    proof = []
    
    for base in range(2,11):
        value = 0
        for i in range(len(cand)):
            value += int(cand[-i-1]) * (base ** i)
        
        divisor = find_divisor(value)
        
        if divisor < value:
            proof.append(divisor)
        else:
            return None
        
    return proof

def main(n, j):
    found = dict()
    
    while len(found) < j:
        cand = [random.randint(0,1) for r in range(n)]
        cand[0] = cand[n-1] = 1
        
        proof = find_proof(cand)
        
        if not proof is None:
            cand = ''.join([str(x) for x in cand])
            found[cand] = proof
        
    print "Case #1:"
    
    for cand in found:
        proof = found[cand]
        
        print cand,
        print ' '.join([str(x) for x in proof])

if __name__ == '__main__':
    main(int(sys.argv[1]), int(sys.argv[2]))
    
