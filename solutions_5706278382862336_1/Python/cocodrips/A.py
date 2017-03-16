import difflib, collections, math

def solve(p, q):

    p, q = yakubun(p, q)

    c = 1
    while 2 * p < q:
        if q % 2 == 0:
            q //= 2
        else:
            return -1
        c +=1

    for i in xrange(1, 41):
        if 1 << i == q:
            return c

    print p, '/', q, c
    return -1

def yakubun(p, q):
    pt = prime_decomposition(p)
    qt = prime_decomposition(q)

    for i in xrange(len(qt)):
        if qt[i] in pt:
            pt.remove(qt[i])
            qt[i] = 1

    ppp = 1
    for pp in pt:
        ppp *= pp

    qqq = 1
    for qq in qt:
        qqq *= qq

    return (ppp, qqq)



def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table



if __name__ == "__main__":
    with open('inputAl.txt', 'r') as infile, open('outputA.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(line.split())

        T = int(data[0][0])
        data.pop(0)

        for t in xrange(T):
            p, q = map(int, data[0][0].split('/'))
            data.pop(0)
            ans = solve(p, q)
            if ans < 0:
                str = "Case #{0}: {1}\n".format(t+1, 'impossible')
            else:
                str = "Case #{0}: {1}\n".format(t+1, ans)

            outfile.write(str)


