import random

# For accuracy of primality check
k=10

def modpow(n,k,m):
    if k==1: return n%m
    t = modpow(n,k/2,m)
    t = (t*t)%m
    if k%2 != 0:
        t = (t*n)%m
    return t


def isprime(n):
    d = n-1
    r=0
    while d%2==0:
        d/=2
        r+=1
    for i in xrange(k):
        a = random.randrange(2,n-2)
        x = modpow(a,d,n)
        if x==1 or x==n-1:
            continue
        for j in xrange(r-1):
            x=(x**2)%n
            if x == 1: return False
            if x == n-1: break
        if x == n-1: continue
        return False
    return True

def coin2num(coin,b):
    ret = 0
    bb = 1
    while coin != 0:
        if (coin&1):
            ret += bb
        bb *= b
        coin>>=1
    return ret

def coin2str(coin,N):
    s = ""
    for i in xrange(N):
        if coin&1:
            s = "1"+s
        else:
            s = "0"+s
        coin >>=1
    return s

def finddivisors(coin):
    ret = []
    for base in xrange(2,11):
        num = coin2num(coin,base)
        good = False
        for trial in xrange(2,10000):
            if (trial >= num): break
            if num%trial == 0:
                ret.append(trial)
                good=True
                break
        if not good: return None
    return ret

def main():
    i = 0
    T=int(raw_input())
    for tc in xrange(T):
        N,J = (int(s) for s in raw_input().split())
        print "Case #%d:" % (tc+1)
        for interior in xrange(2**(N-2)):
            coin = 1|(interior<<1)|(1<<(N-1))
            #print(coin2str(coin))
            good = True
            for base in xrange(2,11):
                if isprime(coin2num(coin,base)):
                    good = False
                    break
            if not good: continue
            divs = finddivisors(coin)
            if divs is not None:
                i+= 1
                print coin2str(coin,N),' '.join(str(n) for n in divs)
            if i >= J: break

if __name__ == '__main__':
    main()
