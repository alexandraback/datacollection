CurrentPathIn = "input.txt"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")

import math

def divisor(n):
    for i in range(2,math.ceil(math.sqrt(n))):
        if n%i==0:
            return i
    return 0

def sample(i, n):
    s = bin(i)
    s = s[2:]
    s = '0'*(n - len(s)) + s
    return '1'+s+'1'

def tobase(s, base):
    res = 0
    for i in range(len(s)):
        if s[i]=='0':
            pass
        else:
            res+=1
        if (i!=len(s)-1):
            res*=base
    return res

def isJam(s):
    divs = {}
    for base in range(2,11):
        t = tobase(s, base)
        x = divisor(t)
        if x==0:
            return [False]
        else:
            divs[base] = x
    return [True,divs]

def foo(N, J):
    res = {}
    for i in range(2**(N-2)):
        s = sample(i, N-2)
        x = isJam(s)
        if x[0]:
            res[s] = x[1]
        if len(res) >= J:
            break
    return res
        
T = int(fr.readline())
for t in range(T):
    N,J = fr.readline().split()
    N, J = int(N), int(J)
    res = foo(N,J)
    
    fw.write("Case #1:\n")
    for k in res:
        s = ""
        for k1 in res[k]:
            s+=" "+str(res[k][k1])
        fw.write(k+s+"\n")

fr.close()
fw.close()
