import random
from sys import stdout

N = 32
J = 500

def is_prime(n):
    a = random.randint(2, n-1)

    def pow(k):
        if k == 0: return 1
        ret = pow(k/2)
        return ret * ret * (1 if k%2 == 0 else a) % n

    return pow(n-1) % n == 1

def convert(s, base):
    res = 0
    for d in s:
        res = res * base + int(d)
    return res

def test(s):
    for base in xrange(2, 11):
        if is_prime(convert(s, base)):
            return False
    return True

def test2(s):
    for base in xrange(2, 11):
        if find_divisor(convert(s, base)) == None:
            return False
    return True

def find_divisor(n):
    for i in range(2, 10**5):
        if n%i == 0:
            return i
    return None

print 'Case #1:'
ans = set()
while len(ans) < J:
    s = '1' + ''.join(random.choice('01') for i in xrange(N-2)) + '1'
    if s not in ans and test(s) and test2(s):
        ans.add(s)

for s in ans:
    print s,
    stdout.flush()
    for base in xrange(2, 11):
        print find_divisor(convert(s, base)),
        stdout.flush()
    print
