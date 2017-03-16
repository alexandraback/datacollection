import random
import sys

def is_probable_prime(n, k = 7):
    if n < 6:  # assuming n >= 0 in all cases... shortcut small cases here
        return [False, False, True, True, False, True][n]
    elif n & 1 == 0:  # should be faster than n % 2
        return False
    else:
        s, d = 0, n - 1
        while d & 1 == 0:
            s, d = s + 1, d >> 1
            # Use random.randint(2, n-2) for very large numbers
        for a in random.sample(xrange(2, min(n - 2, sys.maxint)), min(n - 4, k)):
            x = pow(a, d, n)
            if x != 1 and x + 1 != n:
                for r in xrange(1, s):
                    x = pow(x, 2, n)
                    if x == 1:
                        return False  # composite for sure
                    elif x == n - 1:
                        a = 0  # so we know loop didn't continue to end
                        break  # could be strong liar, try another a
                if a:
                    return False  # composite if we reached end of this loop
        return True  # probably prime if reached end of outer loop

t = input()

for tc in range(1, t+1):
    print "Case #"+str(tc)+":"
    n,jamed = raw_input().split()
    n = int(n)
    jamed = int(jamed)
    
    nb = [1]
    for i in range(0,n-2):
        nb.append(0)
    nb.append(1)
    
    while jamed > 0:
        bon = True
        for i in range(2,11):
            isp = 0
            coef = 1
            for j in nb:
                isp += coef*j
                coef = i * coef
            if is_probable_prime(isp,15):
                bon = False
                break
        if bon:
            print '%s' % ''.join(map(str, nb[::-1])),
            jamed -= 1
            for i in range(2,11):
                isp = 0
                coef = 1
                for j in nb:
                    isp += coef*j
                    coef = i * coef
                k = 2;
                while isp % k <> 0:
                    k += 1
                print k,
            print ""

        nb[1] += 1
        i = 1
        while nb[i] == 2:
            nb[i] = 0;
            i += 1
            nb[i] += 1;

