input = open("cocu.in", "r")
output = open("cocu.out", "w")

import sys

def flip(k):
    r = 0
    while k != 0:
        r *= 10
        r += k%10
        k = int(k/10)
    return r

def solve():
    global res, gMAX
    for n in range(2,gMAX + 1):
        if n % 10 != 0:
            fn = flip(n)
            if fn < n:
                res[n] = 1 + min(res[n-1], res[fn])
            else:
                res[n] = 1 + res[n-1]
        else:
            res[n] = 1 + res[n-1]

t = int(input.readline())

query = []

for i in range(t):
    query.append(int(input.readline()))

gMAX = max(query)

res = [-1 for i in range(gMAX+1)]

res[0] = 0
res[1] = 1

solve()

for i in range(len(query)):
    output.write("Case #" + str(1+i) + ": " + str(res[query[i]]) + "\n")

