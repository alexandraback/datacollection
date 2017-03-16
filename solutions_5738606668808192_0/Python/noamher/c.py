import os
import sys
from sets import Set


def main():
    if len(sys.argv) != 2:
        print 'usage: a.py <input_file>'
        sys.exit(1)

    with open(sys.argv[1], 'r') as f, open('res', 'w') as out:
        [count] = map(int, f.readline().split())
        for i in xrange(count):
            [N, J] = map(int, f.readline().split())
            out.write('Case #%d:\n' % (i+1))
            for (num, proofs) in find_coinjams(N, J):
                out.write('%s %s\n' % (num, " ".join([str(x) for x in proofs])))

def find_coinjams(N, J):
    coinjams = []
    for i in xrange(2**(N-2)):
        num = "{0:b}".format((1<<(N-1)) + (i<<1) + 1)
        proofs = []
        for b in range(2, 11):
            proof = is_not_prime(int(num, b))
            if proof == -1:
                break
            else:
                proofs.append(proof)
        if len(proofs) == 9:
            coinjams.append((num, proofs))
        if len(coinjams) == J:
            return coinjams
    raise "Failed to find enough coinjams"

def is_not_prime(num):
    # print "num:" + str(num)
    for proof in xrange(2, int(num**(0.5)) + 2):
        # print num % proof, proof
        if num % proof == 0:
            return proof
    return -1


if __name__ == "__main__":
    main()