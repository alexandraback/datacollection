import sys
import os
import math

def solve(T, inputs):
    '''
    prime_table = [False] * (2 ** 16)
    with open('prime-16.txt') as f_prime:
        for line in f_prime:
            #prime_table.append(int(line.strip()))
            prime_table[int(line.strip())] = True

    print prime_table
    '''

    for t in xrange(T):
        # input variables
        [N, J] = map(lambda s : int(s), inputs[t])
        print "N: %d, J: %d" % (N, J)
        count = 0

        print "Case #%d:" % (t+1)
        for i in xrange(2 ** (N-1) + 1, 2 ** N, 2):
            bit_rep = getBitRep(i)
            #print "i's bit rep: %s" % bit_rep[::-1]

            divisors = [-1] * 11
            div_count = 0
            for base in xrange(2, 11):
                num = 0
                for p in range(N):
                    if bit_rep[p] == '1':
                        num += base ** p
                #print "%d in base %d: %d" % (i, base, num)

                '''
                if prime_table[num]:
                    break
                else:
                    divisors[base] = findDivisor(num)
                    div_count += 1
                '''

                div = findDivisor(num)
                if div > 0:
                    divisors[base] = div
                    div_count += 1
                else:
                    break
            
            if div_count == 9:
                print "%s %s" % ("".join(bit_rep[::-1]), 
                        " ".join(map(lambda i : str(i), divisors)[2:]))
                count += 1

            if count == J:
                break

def getBitRep(x):
    i = x
    bit_rep = []
    while i:
        bit_rep.append(str(i % 2))
        i //= 2
    return bit_rep

def findDivisor(x):
    for d in range(2, int(math.ceil(math.sqrt(x)))):
        if x % d == 0:
            return d
    return -1

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
