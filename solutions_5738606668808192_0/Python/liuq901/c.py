import primesieve

def prime(x):
    it = primesieve.Iterator()
    it.skipto(x - 1)
    return x == it.next_prime()

def check(x):
    x = bin(x)[2:]
    for i in xrange(2, 11):
        y = int(str(x), i)
        if prime(y):
            return False
    return True

def result(x):
    x = bin(x)[2:]
    print x,
    for i in xrange(2, 11):
        y = int(str(x), i)
        for j in xrange(2, y):
            if y % j == 0:
                print j,
                break
    print

raw_input()
n, m = map(int,raw_input().split())
print 'Case #1:'
x = int('1' + '0' * (n - 2) + '1', 2) - 2
for i in xrange(m):
    while True:
        x += 2
        if check(x):
            result(x)
            break
