def getvalue(line):
    res = line.split(' ')
    for i in range(len(res)):
        res[i] = int(res[i])
    return res

def parse(path):
    files = open(path)
    files.readline()
    content = files.readlines()
    for i in range(len(content)):
        content[i] = getvalue(content[i])
    return content

def firstdiv(n):
    if (n%2 == 0):
        return 2
    k = 3
    while(n%k != 0):
        k += 2
    return k

def expmod(b,e,m):
    if (e == 1):
        return b
    if(e%2):
        res=expmod(b,e-1,m)*b
    else:
        res=expmod(b,e//2,m)*expmod(b,e//2,m)
    res = res % m
    return res

def isprime(n):
    return (expmod(2,n-1,n) == 1 and expmod(3,n-1,n) == 1 and expmod(5,n-1,n) == 1 and expmod(7,n-1,n) == 1 and expmod(11,n-1,n) == 1)

def nextstep(L):
    L[0]+=2
    for i in range(1,9):
        tmp = L[0]
        L[i] = 0
        k = 0
        while(tmp>0):
            L[i]+=(i+2)**k * (tmp%2)
            tmp = tmp // 2
            k+=1
    return L


def coinnaive(number, size):
    L = []
    current = 0
    res = []
    for i in range (2,11):
        L.append(i**(size-1)+1)
    while (current < number and L[0] < 2 ** size+1):
        print "newloop"
        print L
        notprime = True
        for i in range(9):
            if(isprime(L[i])):
                print "i failed", i+2
                notprime = False
                break
        if(notprime):
            res.append(L[8])
            print "new"
            for i in range(9):
                print "adding div"
                res.append(firstdiv(L[i]))
            current += 1
        L=nextstep(L)
    return res


def getnum(lel,n):
    res = 10**(n-1)+1
    k = 0
    while (lel>0):
        res += (lel%2 * (10**(n-1-k) + 10**k))
        lel = lel // 2
        k += 1
    return str(res)

def coin(n,j):
    res = ["Case #1:\n"]
    lel = 0
    for i in range(j):
        res.append(getnum(lel,n)+" 3 4 5 6 7 8 9 10 11\n")
        lel += 2
    return res

def output():
    data = parse("C-large.in")
    L = coin(data[0][0],data[0][1])
    output=(open("outputcoin.out","w"))
    output.writelines(L)

output()
    
