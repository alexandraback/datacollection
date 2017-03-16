d = {}

def f(a,b,k,A,B,K):
    if (A,B,K) in d:
        return d[(A,B,K)]
    if A < 10 and B < 10 and K < 10:
        r = pls(A,B,K)
        d[(A,B,K)] = r
        return r
    #print a,b,k,A,B,K
    t = 0
    l = len(a)
    aa = (a[0] == "1")
    bb = (b[0] == "1")
    kk = (k[0] == "1")
    n = 1 << (l-1)
    r = 0
    if kk:
        if aa and bb:
            r = n*(A+B-n)+f(a[1:],b[1:],k[1:],A^n,B^n,K^n)
        else:
            r = f(a,b,"0"+"1"*(l-1),A,B,n-1)
    else:
        if aa and bb:
            if not A^n and not B^n:
                r = 2*K+f("1"*(l-1),"1"*(l-1),k[1:],n-1,n-1,K)
            else:
                r = f("1"+"0"*(l-1),"1"+"0"*(l-1),k,n,n,K)+f("1"+"0"*(l-1),"0"+b[1:],k,n,B^n,K)+f("0"+a[1:],"1"+"0"*(l-1),k,A^n,n,K)
        elif aa and not bb:
            if not A^n:
                r = min(B,K)+f("0"+"1"*(l-1),b,k,n-1,B,K)
            else:
                r = f("1"+"0"*(l-1),b,k,n,B,K)+f(a[1:],b[1:],k[1:],A^n,B,K)
        elif not aa and bb:
            if not B^n:
                r = min(A,K)+f(a,"0"+"1"*(l-1),k,A,n-1,K)
            else:
                r = f(a,"1"+"0"*(l-1),k,A,n,K)+f(a[1:],b[1:],k[1:],A,B^n,K)
        else:
            r = f(a[1:],b[1:],k[1:],A,B,K)
    d[(A,B,K)] = r
    #if pls(A,B,K) != r:
    #    print "wtf",A,B,K,r,pls(A,B,K)
    return r

def pls(a,b,k):
    t = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                t += 1
    return t

t = int(raw_input())
tt = 1
while tt <= t:
    a, b, k = [int(i) for i in raw_input().split()]
    A, B, K = a, b, k
    a = bin(a)[2:]
    b = bin(b)[2:]
    k = bin(k)[2:]
    l = max(len(a),len(b),len(k))
    a = "0"*(l-len(a))+a
    b = "0"*(l-len(b))+b
    k = "0"*(l-len(k))+k
    #print a,b,k,f(a,b,k,A,B,K)
    print "Case #{0}: {1}".format(tt,f(a,b,k,A,B,K))
    tt += 1