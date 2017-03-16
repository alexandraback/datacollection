import sys

def show(x):
    pass

def tobase(coin, b):
    bb = 1
    v = 0
    while coin > 0:
        if coin & 1:
            v += bb
        coin /= 10
        bb *= b
    return v
            
#
#def pow(a, b):
#    return pow(a,int(b/2))**2 * (b if b&1 else


def primes(PRIMES):
    primes = [2]
    streaks = {2: 2}
    nums = {}
    i = 3
    while len(primes) < PRIMES:
        while i in nums:
            nums_i = nums.pop(i)
            nextnum = i + nums_i * 2
            while nextnum in nums:
                nextnum += nums_i * 2
            nums[nextnum] = nums_i
            i += 2
        nums[i*3] = i
        primes.append(i)
        i += 2

    return primes

def fermtest(n, safe=False):
    assert n > 1
    if n == 2:
        return 1
    if not n & 1:
        return 0
    a = 2**61 - 1
    a = 2
    assert n % a != 0
    e = n - 2
    v = a
    fast = [(2, (a**2) % n)]
    for k in xrange(1337000):
        top, num = fast[0]
        if top + top > e:
            break
        fast.insert(0, (top + top, (num*num) % n))
    while e > 0:
        while fast and fast[0][0] > e:
            fast.pop(0)
        if fast and not safe:
            assert fast[0][0] <= e
            e -= fast[0][0]
            v = (v * fast[0][1]) % n
        else:
            e -= 1
            v = (v * a) % n
    assert e == 0
    return v

P = 2**61 - 1
PP = P - 1
_primes = set(primes(10000))
_biggest = max(_primes)

def maybeprime(n):
    if n in _primes:
        return True, True
    elif n < _biggest:
        return False, True
    else:
        return fermtest(n) == 1, False
        # return ((P ** (n-1)) % n) == 1, False


def solve(N, J):
    for n in xrange(2**(N-1)+1, 2**N, 2):
        solution = []
        nums = []
        coin = int("{0:b}".format(n))
        # print "n =", n, "coin=", coin
        for b in range(2,11):
            v = tobase(coin, b)
            #print "base=", b, "v=",v
            is_prime, confident = maybeprime(v)
            if is_prime:
                break  # next coin
            for i in xrange(3, min(v, 100000), 2):
                if v % i == 0:
                    #print coin, i, "divides", v
                    solution.append(i)
                    nums.append(v)
                    found_divisor = True
                    break
            else:
                found_divisor = False
                break
        if is_prime:
            # print "Skipping", v, "was prime", coin, "in base", b
            continue
        if not found_divisor:
            # print "Could not find number which divides", v
            pass
        else:
            print coin, ' '.join(map(str, solution)) # , ' '.join(map(str, nums))
            J -= 1
            if J == 0:
                break
    else:
        assert False, "Could not solve."
                    

if __name__ == "__main__":
    f = open("C.in")
    fout = open("C.out", "w")

    #primes = primes(2**20)
    lines = f.read().splitlines()
    interp_line = lambda x: map(int, x.split(" "))
    for idx, (N, J) in enumerate(map(interp_line, lines[1:])):
        print "Case #%d" % (1+idx)
        solve(N, J)
        break

    f.close()
    fout.close()
