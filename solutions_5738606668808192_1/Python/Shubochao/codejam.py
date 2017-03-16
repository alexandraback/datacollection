import sys
import os
import math

def solve(T, inputs):
    for t in xrange(T):
        # input variables
        [N, J] = map(lambda s : int(s), inputs[t])
        print "Case #%d:" % (t+1)

        NN = (N-4)/2
        count = 0
        for i in xrange(0, 2**NN):
            part_bit_rep = getBitRep(i, NN)
            part_bit_rep.insert(0, "1")
            part_bit_rep.append("1")
            #print "part: %s" % part_bit_rep

            bit_rep = part_bit_rep * 2

            divisors = map(lambda base : str(getNum(part_bit_rep, base)), range(2, 11))
            
            print "%s %s" % ("".join(reversed(bit_rep)), " ".join(divisors))
            count += 1
            if count == J:
                break

def getNum(bit_rep, base):
    res = 0
    exp = 1
    for b in bit_rep:
        res += int(b) * exp
        exp *= base
    return res

def getBitRep(x, N):
    i = x
    n = N
    bit_rep = []
    while n > 0:
        bit_rep.append(str(i % 2))
        i //= 2
        n -= 1
    return bit_rep

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
