def minimal_prime_divisor(number):
    curr = 2
    while curr * curr <= min(number, 1000):
        if number % curr == 0:
            return curr
        curr += 1
    return number

N, J = 32, 500
multiples = []
for i in xrange(2, 11):
    multiples.append(map(lambda k: i**k, xrange(N)))
mask = -1
solutions = []
while len(solutions) < J:
    mask += 1
    divisors = []
    for polynomial in multiples:
        copymask = mask
        number = polynomial[0] + polynomial[-1]
        for i in xrange(1, N-1):
            number += (copymask & 1) * polynomial[i]
            copymask >>= 1
        mpd = minimal_prime_divisor(number)
        if mpd == number:
            divisors = None
            break
        divisors.append(mpd)
    if divisors is not None:
        solutions.append(["1{1:{0}b}1".format(N-2, mask).replace(" ", "0")] + divisors)
out = open("output.txt", "w")
out.write("Case #1:\n")
for s in solutions:
    out.write(" ".join(map(str, s)) + "\n")
out.close()