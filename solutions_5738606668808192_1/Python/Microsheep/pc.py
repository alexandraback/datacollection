import sys

def isprime(n):
    k=0
    if n==1:
        return 1
    if n==2 or n==3:
        return -1
    if n%2 == 0:
        return 2
    if n%3 == 0:
        return 3
    i = 5
    w = 2
    while i*i <= n:
        if k>1000:
            return -1
        if n % i == 0:
            return i
        i = i + w
        w = 6 - w
        k = k+1
    return -1

T = input()
for times in range(0,int(T)):
    NJ = input()
    N=int(NJ.split()[0])
    J=int(NJ.split()[1])
    ans = []

    for test in range(0,2**(N-2)):
        if len(ans)==J:
            break
        pos = []
        pos.append("1"+bin(test)[2:].zfill(N-2)+"1")
        for base in range(2,11):
            now = isprime(int(pos[0],base))
            if(now==-1):
                break
            else:
                pos.append(now)
        if len(pos)==10:
            ans.append(pos)
            sys.stderr.write(str(pos)+'\n')

    print("Case #"+str(times+1)+":")
    for item in ans:
        for a in range(0,9):
            print(str(item[a]), end=" ")
        print(str(item[9]))

