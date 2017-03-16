__author__ = 'dkopiychenko'


def notPrime(n):
    for i in xrange(2,100):
        if n % i == 0: return True
    return False

def divisors(s):
    l = []
    for j in xrange(2,11):
        n = int(s,j)
        for i in xrange(2,100):
            if n % i == 0:
                l.append(i)
                break
    return l

def check(i):
    s = bin(i)[2:]
    for j in xrange(2,11):
        n = int(s,j)
        if not notPrime(n): return False
    return True

print 'Case #1:'

c = 0
x = 16
y = 50
for i in xrange(2**(x-1)+1,2**x,2):
    if c == y: break
    if check(i):
        s = bin(i)[2:]
        print s, ' '.join(map(str,divisors(s)))
        c += 1
#print c

# for i in xrange(1000):
#     s = bin(i)[2:]
#     n = int(s,3)
#     if n % 3 == 1 and n % 5 == 0:
#         print s,n
