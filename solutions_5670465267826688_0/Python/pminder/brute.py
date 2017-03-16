#coding:utf8
import sys
sys.setrecursionlimit(100000)

memory = {}
multiplication = {
        ('1', '1'): '1',
        ('1', 'i'): 'i',
        ('1', 'j'): 'j',
        ('1', 'k'): 'k',

        ('i', '1'): 'i',
        ('i', 'i'): '-1',
        ('i', 'j'): 'k',
        ('i', 'k'): '-j',

        ('j', '1'): 'j',
        ('j', 'i'): '-k',
        ('j', 'j'): '-1',
        ('j', 'k'): 'i',

        ('k', '1'): 'k',
        ('k', 'i'): 'j',
        ('k', 'j'): '-i',
        ('k', 'k'): '-1',
        }

def mul(a, b):
    res = multiplication[a[-1], b[-1]]
    sign = (-1)**(len(a) + len(b))

    if sign == 1:
        return res
    elif len(res) == 1:
        return '-' + res
    else:
        return res[-1]

def mulstring(s, t=0):

    if s in memory:
        return memory[s]

    if len(s) == 1:
        return s

    if t == 0:
        memory[s] = mul(mulstring(s[:len(s)-1], t), s[-1])
#    if t == 1:
#        memory[s] = mul(s[0], mulstring(s[1:], t))
    return memory[s]

def mulstring3(s):

    sign = 0
    while len(s) > 1 + sign:
        c = mul(s[0]+sign*s[1], s[1+sign])
        s = c + s[2+sign:]

        if len(c) == 2:
            sign = 1
        else:
            sign = 0
    return s

def mulstring2(s, S):

    a = mulstring(S)
    b = mulstring(S[:len(S) - len(s)])

    c = mul(b, a)
    if len(c) == 2:
        return c[-1]
    else:
        return '-' + c

def solve():
    L, X = input().split(' ')
    X = int(X)
    L = X*int(L)
    s = input()
    s = X*s

#    if mulstring(s) == '-1':
#        return 'YES'
#    else:
#        return 'NO'

    ip, jp = [], []

    for i in range(1, L - 1):
        if mulstring(s[:i]) == 'i':
            if mulstring2(s[i:],s) == 'i':
                ip.append(i)
    for j in range(2, L):
        if mulstring2(s[j:], s) == 'k':
            if mulstring(s[:j]) == 'k':
                jp.append(j)

    if ip != [] and jp != []:
        return 'YES'

    return 'NO'

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        r = solve()
        print("Case #{}: {}".format(i+1, r.upper()))
