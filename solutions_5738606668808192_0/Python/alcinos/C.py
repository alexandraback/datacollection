def isPrime(n):
    if (n == 0 or n == 1):
        return -1;
    if (n == 2 or n == 3 or n == 5 or n == 7):
        return -1;
    if (n % 2 == 0):
        return 2;
    if (n % 3 == 0):
        return 3;
    i = 5
    while(i*i<=n):
        if (n % i == 0 ):
            return i;
        if ( n % (i + 2) == 0):
            return i+2;
        i+=6
    return -1;
def tobin(i):
    return "{0:b}".format(i)


T=int(input())
t = input().split()
N = int(t[0])
J = int(t[1])
print("Case #1:")
i = (1<<(N-1))+1
while(J>0 and i<(1<<N)):
    cur = tobin(i);
    ok = True;
    res = [];
    for base in range(2,11):
        nbr = int(cur,base);
        div = isPrime(nbr);
        if(div == -1):
            ok = False;
            break;
        res.append(div);
    if(ok):
        st = cur 
        for s in res:
            st += " " + str(s)
        print(st)
        J-=1;
    i+=2
