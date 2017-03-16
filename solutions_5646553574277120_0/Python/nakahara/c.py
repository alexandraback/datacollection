import math
from itertools import combinations

def addNew(pn, newC):
    pos = pn[0].copy()
    need = pn[1].copy()
    for i in pn[0]:
        pos.add(i+newC)
        need.discard(i+newC)
    
    return (pos,need)

def solve():
    a=input()
    C=int(a.split()[0])
    D=int(a.split()[1])
    V=int(a.split()[2])
    coins = input().split()
    coins = [int(i) for i in coins]

    pn =(set([0]),set(range(1,V+1)))
    for i in coins:
        pn = addNew(pn, i)

    num = 1
    dp = {():pn}
    if pn[1] == set():
        return "0"

    while True:
        for i in combinations(pn[1], num):
            search = i[:-1]
            newpn = dp[search]
            newpn = addNew(newpn,i[-1])
            dp[i]=newpn
            if newpn[1]==set():
                return str(num)
        num+=1
    return

T=int(input());

for t in range(1,T+1):
    print ("Case #" + str(t) + ": " + solve())