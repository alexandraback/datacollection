divisor = -1
def isprime(n):
    global divisor
    """Returns True if n is prime."""
    if n == 2:
        return True
    if n == 3:
        return True
    if n % 2 == 0:
        divisor = 2
        return False
    if n % 3 == 0:
        divisor = 3
        return False
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            divisor = i
            return False
        i += w
        w = 6 - w
    return True

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
while(cnt <= J and num < num_max):
    good = True
    base = 2
    f = []
    while(base <= 10):
        tn = convertToBase(num, base)
        if (isprime(tn)):
            good = False
            break
        else:
            f.append(divisor)
        base = base + 1

    if (good):
        print "%s %s" % (str(convertToBase(num, 10)), " ".join(map(str, f)))
        cnt = cnt + 1
    num = num + 2
