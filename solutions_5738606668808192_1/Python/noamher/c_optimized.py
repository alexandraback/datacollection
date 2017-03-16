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
    print N
    for i in xrange(2**(N-2)):
        # print i, even_count(i), odd_count(i)

        if even_count(i) != odd_count(i):
            continue

        calculated_num = (1<<(N-1)) + 1 + (i<<1)
        num = "{0:b}".format(calculated_num)

        # print i, num

        proofs = []
        for b in range(2, 11):
            proof = is_not_prime(int(num, b))
            if proof == -1:
                break
            else:
                proofs.append(proof)
        if len(proofs) == 9:
            coinjams.append((num, proofs))
            print len(coinjams)
        if len(coinjams) == J:
            return coinjams
    raise Exception("Failed to find enough coinjams")

def odd_count(num):
    bin = "{0:b}".format(num)
    count = 0
    for i in xrange(len(bin)):
        if i%2==1 and bin[i] == '1':
            count += 1
    return count

def even_count(num):
    bin = "{0:b}".format(num)
    count = 0
    for i in xrange(len(bin)):
        if i%2==0 and bin[i] == '1':
            count += 1
    return count

def is_not_prime(num):
    # print "num:" + str(num)
    for proof in xrange(2, int(num**(0.5)) + 2):
        # print num % proof, proof
        if num % proof == 0:
            return proof
    return -1


if __name__ == "__main__":
    main()