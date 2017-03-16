from math import sqrt
file = open("pancakes.in", "r")

filew = open("pancakes.out", "w")

m = [[-1 for j in range(1001)] for i in range(1001)]

def run(d, p, t):
    L = max(p)
    res = 1001
    for i in range(1, L+1):
        r = 0
        for x in p:
            r += int((x - 1)/i)
        r += i
        res = min(res, r)
    p.sort()
    filew.write("Case #" + str(t+1) + ": " + str(res) +  "\n")

t = int(file.readline())

for i in range(t):
    d = int(file.readline())
    x = file.readline().split()
    p = [int(y) for y in x]
    run(d, p, i)

