import sys
import os
import math

def solve(T, inputs):
    for t in xrange(T):
        # input variables
        [K, C, S] = map(lambda s : int(s), inputs[t])
        
        indexes = _solve(K, C, S)
        print "Case #%d: %s" % (t+1, " ".join(indexes) if indexes else "IMPOSSIBLE")

def _solve(K, C, S):
    if math.ceil(float(K)/C) > S:
        return None

    indexes = []
    if C > K:
        C = K

    digit = 0
    for i in xrange(0, K, C):
        idx = 0
        for j in xrange(C):
            if digit == K:
                digit = K-1
            #print "%d * (%d ** %d) = %d" % (digit, K, j, idx)
            idx += digit * (K**j)
            digit += 1

        #print "idx: %d" % idx
        indexes.append(str(idx+1))

    return indexes

def main():
    if len(sys.argv) < 2:
        sys.exit("Usage: %s [input]" % sys.argv[0])

    if not os.path.exists(sys.argv[1]):
        sys.exit("Input file %s does not exist!" % sys.argv[1])
 
    with open(sys.argv[1]) as f:
        lines = f.readlines()
        T = int(lines[0])
        inputs = map(lambda l : l.split(' '), lines[1:])

    solve(T, inputs)

if __name__ == "__main__":
    main()
