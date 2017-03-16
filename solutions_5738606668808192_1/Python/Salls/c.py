import random
import sys

#with open(sys.argv[1]) as f:
#    lines = f.readlines()

def is_prime(n):
    if n % 2 == 0 or n % 3 == 0:
        return False

    for f in xrange(5, min(int(n ** .5)+2, 10000), 6):
        if n % f == 0 or n % (f + 2) == 0:
            return False
    if f > 10000-10:
        return True
    return True

def is_good(s):
    for i in xrange(2,11):
        if is_prime(int(s,i)):
            return False
    return True

def any_divisor(n):
    for f in xrange(2, int(n ** .5)+2):
        if n%f == 0:
            return f
    raise Exception("wtf")

def get_divisors(s):
    divisors = []
    for i in xrange(2,11):
        divisors.append(any_divisor(int(s,i)))
    return " ".join(map(str, divisors))

#T = int(lines[0],10)
T = 1
for tt, l in enumerate([1]):
    N = 32
    J = 500
    
    found = set()
    max_num = (1 << N) - 1
    while len(found) < J:
        r = random.randint(0, max_num)
        s = bin(r).replace("0b","").replace("L","").rjust(N,"0")
        if not s.startswith("1"):
            continue
        if not s.endswith("1"):
            continue
        if is_good(s):
            #print s
            found.add(s + " " + get_divisors(s))
    
    print ("Case #%d:" % (tt+1))
    for s in found:
        print s

        

