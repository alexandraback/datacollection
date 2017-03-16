import time
divisor = -1
def isprime(n):
    global divisor
    """Returns True if n is prime."""
    if n == 2:
        return 1
    if n == 3:
        return 1
    if n % 2 == 0:
        divisor = 2
        return 0
    if n % 3 == 0:
        divisor = 3
        return 0
    i = 5
    w = 2
    while i <= 1000:
        if n % i == 0:
            divisor = i
            return 0
        i += w
        w = 6 - w
    return 2

def convertToBase(n, b):
    i = 0
    ret = 0
    while(n):
        if (n&1):
            ret = ret + pow(b, i)
        i = i+1
        n = n//2
    return ret


T = input()
N, J = raw_input().split()
N = int(N)
J = int(J)

print "Case #%d:" % (T)

num = (1 << (N-1)) + 1
num_max = (1 << N)
cnt = 1
prevnum = num
while(cnt <= J and num < num_max):
    if (num-prevnum >= 10000):
        prevnum = num
        time.sleep(0.1)
    good = True
    base = 2
    f = []
    while(base <= 10):
        tn = convertToBase(num, base)
        is_prime_check = isprime(tn)
        if (is_prime_check == 1 or is_prime_check == 2):
            good = False
            break
        else:
            f.append(divisor)
        base = base + 1

    if (good):
        print "%s %s" % (str(convertToBase(num, 10)), " ".join(map(str, f)))
        cnt = cnt + 1
    num = num + 2
