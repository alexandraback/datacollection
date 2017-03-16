import math
import random

T = 1
N = 32
J = 500

def get_fact(x):
    for i in range(2, 1000): # We hope that there are lots of jamcoins
        if x % i == 0:
            return i
    return 1

def compute(x, base):
    aux = 0;
    mult = 1;
    while x:
        aux += mult * (x & 1)
        x >>= 1
        mult *= base
    return aux

ans = []
for j in range(1 << (N - 2)):
    new_j = (1 << (N - 1)) + (j << 1) + 1
    facts = []
    ok = True
    for k in range(2, 11):
        val = compute(new_j, k)
        aux = get_fact(val)
        if (aux != 1):
            facts.append(aux)
        else:
            ok = False
            break
    if ok:
        ans.append((new_j, facts))
        #print(len(ans))
        if len(ans) >= J:
            break

f = open("dataset.out", "w")
f.write("Case #1:\n")
for j in range(J):
    v = []
    aux = ans[j][0]
    while aux:
        v.append(aux & 1)
        aux >>= 1
    s = ""
    for k in range(len(v)):
        s += str(v[len(v) - k - 1])
    s += " "
    for k in range(9):
        if k == 8:
            s += str(ans[j][1][k]) + "\n"
        else:
            s += str(ans[j][1][k]) + " "
    f.write(s)
f.close()
