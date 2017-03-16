from math import sqrt

def next(b, n):
    k = n-2
    a = True;
    while a:
        if b[k] == 1:
            b[k] = 0
        else:
            b[k] = 1
            a = False
        k -= 1

def prime(a):
    for i in range(2, 131071):
        if a%i == 0:
            return i
    return -1

f = open("rep.txt", 'w')
st = "Case #1:\n"
n = 32
j = 500
b = [0 for i in range(n)]
e = [0 for i in range(n)]
b[0] = 1
b[n-1] = 1
k = 0
while k < j:
    ok = True
    for p in range(2, 11):
        a = 0
        for i in range(0, n):
            if b[i] == 1:
                a += p ** (n-i-1)
        pr = prime(a)
        if pr == -1:
            ok = False
            break
        else:
            e[p-1] = pr
            if p == 10:
                e[0] = a
    if ok:
        for z in range(0, 9):
            st += str(e[z]) + " "
        st += str(e[9]) + "\n"
        k += 1
    next(b, n)
f.write(st)
