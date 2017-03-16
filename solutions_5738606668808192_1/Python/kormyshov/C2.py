def isPrime(n):
    pr = [2, 3, 5, 7, 11, 13, 17]
    for i in pr:
        if n % i == 0:
            return i
    return 0

def toString(a):
    res = ''
    while a>0:
        res = '' + chr(48+(a&1)) + res
        a >>= 1
    return res

def solve(n, k):
    b = 1<<(n-1) | 1
    res = dict()
    for i in range(b, 1<<n, 2):
        d = isPrime(i)
        if d > 0:
            v = [d];
            for j in range(3, 11, 1):
                a = 0
                p = 1
                for ii in range(0, n, 1):
                    a += p*(i >> ii & 1)
                    p *= j

                d = isPrime(a)
                if d == 0:
                    break

                v.append(d)

            if len(v) == 9:
                res[i] = v;

        if len(res) == k:
            break;

    f = open("output.txt", "w")
    print("Case #1:", file=f)
    for i in res:
        print(toString(i), end=' ', file=f)
        for j in res[i]:
            print(j, end=' ', file=f)
        print('', file=f)


solve(32, 500)
