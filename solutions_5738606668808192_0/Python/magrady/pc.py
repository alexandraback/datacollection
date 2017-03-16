import sys,random
def NotPrime(n):
    for i in [2,3,5,7,11,13,17,19,23,29]:
        if n % i == 0:
            return i
    return None

def GoodNumberDiv(s):
    t = [NotPrime(int(s,b)) for b in range(2,11)]
    if t.count(None) > 0:
        return None
    return tuple(t)

def RandomBinary(n):
    return ''.join(['01'[random.randint(0,1)] for i in range(n)])

def RandomVaild(n):
    if n>=2:
        return '1'+RandomBinary(n-2)+'1'

T = int(sys.stdin.readline())
N, M = map(int, sys.stdin.readline().split(' '))
se = set()
print ('Case #1:')
for i in range(M):
    while True:
        s = RandomVaild(N)
        if s in se:
            continue
        se.add(s)
        g = GoodNumberDiv(s)
        if g is not None:
            break
    print(' '.join([s] + list(map(str,g))))

