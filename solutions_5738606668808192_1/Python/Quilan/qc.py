
#============================================

small_primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97];
def isprime(n):
    if(n==2): return True;
    if(n%2==0): return False;

    for p in small_primes:
        if(p**2>n): break;
        if(not n%p): return False;

    (d,s)=(n-1,0);
    while(not d&1): (d,s)=(d>>1,s+1);

    #some easy bounds to check, values from wiki
    if  (n < 4759123141): rng=[2,7,61];
    elif(n < 2152302898747): rng=[2,3,5,7,11];
    elif(n < 3474749660383): rng=[2,3,5,7,11,13];
    elif(n < 341550071728321): rng=[2,3,5,7,11,13,17];
    else: rng = small_primes;

    for a in filter(lambda x: x<n, rng):
        ip=False;
        for r in xrange(0,s):
            v=pow(a,d*2**r,n);
            if((v==1 and r==0) or v==n-1):
                ip=True;
                break;
        if(ip==False): break;
        ip=True;

    return ip;

def solveProblem(N,J):
    res = [];
    c=0;
    for n in xrange(1<<N-2):
        arr = [ str(int((n & (1<<i))>0)) for i in xrange(N-2) ];
        v = "1" + "".join(arr) + "1";
        mul = [ int(v,d) for d in xrange(2,11) ];
        if any(True == isprime(d) for d in mul): continue;

        arr=[];
        for m in mul:
            for p in small_primes:
                if p**2 > m: break;
                if m % p > 0: continue;
                arr.append(p);
                break;
            else: break;
        if len(arr) < 9: continue;

        res.append("%s %s"%(v, " ".join(map(str,arr))));
        c += 1;
        if c >= J: break;

    res = "\n%s"%("\n".join(res));
    return res;

#============================================

#from globals import isprime, small_primes;
from time import time;

if __name__ == '__main__':
    outfile = "C.out";

    start=time();
    with open(outfile,"wt") as f:
        res = [ solveProblem(32,500) ];

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
