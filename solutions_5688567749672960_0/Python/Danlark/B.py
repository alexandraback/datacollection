from copy import deepcopy
ouf = open('output.txt', 'w')
t = int(input())


def reversenum(n):
    s = str(n)
    s = s[::-1]
    k = int(s)
    return k

for test in range(t):
    n1 = input()
    l = int(n1)
    if l % 10 == 0:
        l -= 1
        k1 = 1
    else:
        k1 = 0
    n1 = str(l)

    n = [0]*len(n1)
    for i in range(len(n)):
        n[i] = int(n1[i])
    while len(n) > 0:
        s = deepcopy(n)
        k = (len(n))//2
        for j in range(k, len(n) - 1):
            n[j] = 0
        n[len(n) - 1] = 1
        for i in range(len(n)):
            k1 += (- n[i] + s[i])*10**(len(n) - 1 - i)
        s = deepcopy(n)
        for i in range(len(n)//2):
            (n[i], n[len(n) - i - 1]) = (n[len(n) - i - 1], n[i])
        if s == n:
            n.pop()
            for i in range(len(n)):
                n[i] = 9
            if len(n) >= 1:
                k1 += 2
        else:
            k1 += 1
    print('Case #', test + 1, ':', ' ', k1 + 1, sep = '', file = ouf)

ouf.close()






