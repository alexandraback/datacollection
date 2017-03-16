from math import ceil, log, sqrt
import sys

def is_composite(n):
    #bits = int(log(n,2))
    count = int(sqrt(n))
    if count > 1024:
        count = 1024
    for i in range(2, count):
        if n%i==0:
            return True
    return False


def miller_rabin_is_composite(n):
    if n%2 == 0:
        return True
    nn = n-1
    k = -1
    m = -1
    for i in range(1, int(ceil(log(n, 2)))+1):
        if nn % pow(2, i)==0:
            mm = nn / pow(2, i)
            if mm%2 == 1:
                k = i
                m = mm
                break
    if m==-1:
        #print "Cannot run Miller-Rabin test. No power k found such that: n-1=2^k*m"
        return False

    m = int(m)
    #for a in range(2, int(sqrt(n))):
    for a in range(2, 6):
        #print("a:"+str(a)+" m:"+str(m)+" n:"+str(n))
        x = pow(a, m, n)
        liar = False
        if x==1:
            liar = True
            return False
        else:
            for j in range(0, k):
                if x%n == n-1:
                    liar = True
                    return False
                else:
                    x = (x*x)%n
        if not liar:
            return True
    return False

#def is_composite(n)


def is_jamcoin(nstr):
    for i in range(2, 11):
        #if not miller_rabin_is_composite(int(nstr, i)):
        if not is_composite(int(nstr, i)):
            return False
    return True

def get_divisors(nstr):
    div = []
    for i in range(2, 11):
        n = int(nstr, i)
        for j in range(2, int(sqrt(n))):
            if n%j==0:
                div.append(j)
                break
    #print("divisors for "+str(n))
    #printlist(div)
    return div

def printlist(l):
    #print(l)
    print(' '.join(str(x) for x in l))

def print_jamcoins(size, count):
     n = size - 2
     cnt = 0
     for i in range(1, pow(2,n)):
         f = '{0:0'+str(n)+'b}'
         s = f.format(i)
         s = '1'+s+'1'
         if(is_jamcoin(s)):
             l = get_divisors(s)
             print(s, end=" ")
             printlist(l)
             cnt += 1
         if cnt == count:
             break;


name = sys.argv[1]
with open(name) as f:
    lines = f.readlines()
l2 = lines[1]
nn = l2.split()
n = int(nn[0])
j = int(nn[1])
print("Case #1:")
print_jamcoins(n, j)
