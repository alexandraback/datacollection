### Google code jam 2016
### Qualification round
### Coin Jam

def PrimeFactor(n):
    if n%2 == 0:
        return 2;
    p = 3;
    while (p*p < n):
        if n%p == 0:
            return p;
        p += 2;
    return n;

def Primes(N):
    ret = '';
    for i in range(2, 11):
        ret += ' ' + str(PrimeFactor(i**(N/2)+1));
    return ret;

def Generator(N, n):
    val = '1';
    for i in range(N/2-2):
        val = str(n%2)+val;
        n /= 2;
    val = '1'+val;
    return val+val;

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1)
    [N, J] = map(int, raw_input().split());
    primes = Primes(N);
    
    for j in range(J):
        print Generator(N, j) + primes;
    
