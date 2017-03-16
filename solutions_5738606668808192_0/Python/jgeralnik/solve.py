import random

N, J = 16, 50
# N, J = 32, 500

guessed = set()
def generate_guess():
    r = ''.join(random.choice("01") for _ in xrange(N - 2))
    while r in guessed:
        r = ''.join(random.choice("01") for _ in xrange(N - 2))
    guessed.add(r)
    return "1" + r + "1"

def find_factor(n):
    for i in xrange(2, 10000):
        if n % i == 0:
            return i
    return None

def find_all_factors(bitstring):
    # print "Looking for factors for bs", bitstring
    factors = []
    for i in xrange(2, 11):
        n = int(bitstring, i)
        f = find_factor(n)
        if f is None:
            # print "No factors found in base", i, "(%d)" % n
            return None
        factors.append(f)
    return factors

count = 0
print "Case #1:"
while count < J:
    g = generate_guess()
    factors = find_all_factors(g)
    if factors:
        print g, ' '.join(str(f) for f in factors)
        count += 1
