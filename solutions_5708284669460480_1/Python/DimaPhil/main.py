from sys import *
from decimal import *

inp = open("text.in", "r")
out = open("text.out", "w")

T = int(inp.readline())
for test in range(T):
    out.write("Case #" + str(test + 1) + ": ")
    k, l, s = inp.readline().split()
    k = int(k)
    l = int(l)
    s = int(s)
    alphabet = inp.readline().strip()
    need = inp.readline().strip()
    cnt = [0 for i in range(26)]
    for c in alphabet:
        cnt[ord(c) - ord('A')] += 1
    all = k**s
    getcontext().prec = 20
    ans = Decimal(max(0, (s - l + 1))) * Decimal(all)
    fail = False
    for i in range(l):
        symb = ord(need[i]) - ord('A')
        if (cnt[symb] == 0):
            ans = 0
            fail = True
            break
        ans = ans * (Decimal(cnt[symb]) / Decimal(k))
        
    maxAns = 1
    if fail:
        maxAns = 0
    now = need
    for i in range(l, s):
        ok = False
        if len(need) == 1:
            maxAns += 1
            now += need[0]
            continue
        for j in range(i - l + 1, i):
            if now[j:len(now)] == need[0:len(now) - j]:
                now += need[len(now) - j]
                if j == i - l + 1:
                    maxAns += 1
                ok = True
                break
        if ok == False:
            now += need[0]    
    out.write(str(Decimal(maxAns) - ans / Decimal(all)) + "\n")