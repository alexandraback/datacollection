import random

# For accuracy of primality check
k = 50
N = 16
J = 50

def mod_pow(n,k,m):
    # Computes n^k modulo m

    if k == 1: return n % m
    extra = n if (k % 2) else 1
    recurse = mod_pow(n, k//2, m)
    return (recurse*recurse*extra) % m

def is_prime(n):
    r = 0
    d = n-1
    while (d % 2 == 0):
        r += 1
        d /= 2

    for _ in range(k):
        a = random.randrange(2,n-2)
        x = mod_pow(a, d, n)

        if (x == 1 or x == n - 1): continue

        did_finish = True
        for i in range(r-1):
            x = mod_pow(x,2,n)
            if x == 1: return False
            if x == n-1:
                did_finish = False
                break

        if not did_finish: continue
        else: return False

    return True

def convert(digits, base):
    summed = 0
    for (i,j) in zip(digits, range(len(digits)-1,-1,-1)):
        if (i == '1'): summed += base**j

    return summed

def generate():
    i = 0
    while (i < 2**(N-2)):
        last = "{0:b}".format(i) + '1'
        first = '1' + '0'*(N-1-len(last))
        yield first + last
        i += 1

def divisors(number):
    for i in range(2,10000):
        if number % i == 0:
            return i

    return None

print("Case #1:")

answers = []
for i in generate():
    is_jam = True
    for j in range(2,11):
        if (is_prime(convert(i, j))):
            is_jam = False
            break

    if is_jam:
        divides = [divisors(convert(i,j)) for j in range(2,11)]
        if None in divides: continue
        print(("%s " % i) + ' '.join([str(x) for x in divides]))
        answers.append(i)
        if len(answers) == J:
            break