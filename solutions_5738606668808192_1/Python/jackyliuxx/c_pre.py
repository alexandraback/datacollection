#!python3
def conv(s, x) :
    ans = 0
    for i in range(len(s)) :
        ans *= x
        if s[i] == '1' :
            ans += 1
    return ans

def convb(n, l) :
    s = ''
    for i in range(l, 0, -1) :
        if n & (1 << (i - 1)) :
            s += '1'
        else :
            s += '0'
    return s

def getprimes(n) :
    primes = []
    isp = [True] * n
    for i in range(2, n) :
        if isp[i] :
            primes.append(i)
        for j in primes :
            if i * j >= n :
                break
            isp[i * j] = False
            if i % j == 0 :
                break
    return primes

def check(x, primes) :
    for i in primes :
        if i >= x :
            return -1
        if x % i == 0 :
            return i
    return -1
        
primes = getprimes(1000000)
t = int(input())
n, j = input().split()
n = int(n)
j = int(j)

for tsk in range(1, t + 1) :
    print("Case #%d:" % tsk)
    for i in range(0, 2 ** (n - 2)) :
        s = '1' + convb(i, n - 2) + '1'
        op = [str(s)]
        for k in range(2, 11) :
            x = conv(s, k)
            ck = check(x, primes)
            if ck == -1 :
                break
            else :
                op.append(str(ck))
        if len(op) == 10 :
            print(' '.join(op))
            j -= 1
        if j == 0 :
            break
