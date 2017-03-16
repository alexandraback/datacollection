import itertools
import numpy as np

def primesfrom2to(n):
    # http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
    """ Input n>=6, Returns a array of primes, 2 <= p < n """
    sieve = np.ones(n/3 + (n%6==2), dtype=np.bool)
    sieve[0] = False
    for i in xrange(int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[      ((k*k)/3)      ::2*k] = False
            sieve[(k*k+4*k-2*k*(i&1))/3::2*k] = False
    return np.r_[2,3,((3*np.nonzero(sieve)[0]+1)|1)]

primes = primesfrom2to(10000)

print "Case #1:"
i = 0
for s in itertools.product("10",repeat=14):
    s = "1"+"".join(s)+"1"
    nums = [int(s,x) for x in range(2,11)]
    output = []
    for n in nums:
        for p in primes:
            if not n % p and n != p:
                output.append(p)
                break
    if len(output) < 9:
        continue
    #print [(x,y,x%y) for x,y in zip(nums,output)]
    print "{} {}".format(s," ".join([str(x) for x in output]))
    i += 1
    if i >= 50:
        break

