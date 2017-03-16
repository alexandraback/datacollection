import math

def is_prime(x):
    for i in xrange(2, 1000):
        if x % i == 0:
            return i
    return -1




result = []
n, j = 32, 500


for i in xrange(1 << (n - 2)):
    if len(result) == j:
        break
    x = '1'
    for k in xrange(n - 2):
        if i & (1 << k):
            x = '1' + x
        else:
            x = '0' + x
    x = '1' + x
    divs = [x]

    for base in xrange(2, 11):
        div = is_prime(int(x, base))
        if div == -1:
            break
        divs.append(str(div))
    if len(divs) == 10:
        result.append(divs)

print 'Case #1:'
for s in result:
    print ' '.join(s)




