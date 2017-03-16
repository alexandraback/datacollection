import itertools
import gmpy2

def find_divisor(number):
    if gmpy2.is_prime(number):
        return None

    for x in xrange(2, min(number, 10000)):
        if number % x == 0:
            return x
    return None

def check(seq):
    answer = []
    for x in xrange(2, 11):
        number = int(seq, x)
        divisor = find_divisor(number)
        if divisor:
            answer.append(divisor)
        else:
            return None

    return answer

def main(data):
    N, J = data.split()
    N = int(N)
    J = int(J)

    answer = []

    for seq in itertools.product("01", repeat=N-2):
        seq = "1" + "".join(seq) + "1"

        test = check(seq)
        if test:
            answer.append((seq, test))
            if len(answer) >= J:
                break

    for seq, chain in answer:
        print seq,
        for c in chain:
            print c,
        print

T = int(raw_input())
for x in xrange(T):
    print "Case #" + str(x + 1) + ":"
    main(raw_input())
