import sys
from fractions import gcd

path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
file = open(path, "r")
T = int(file.readline())

gs = []
num = 1
for g in range(1, 41):
    num = num * 2
    gs.append(num);

for casenum in range(T):
    P, Q = [int(z) for z in file.readline().split('/')]
    c = int(gcd(P, Q))
    if c > 1:
        P = P // c
        Q = Q // c

    #print(P, Q)
    max_g = 1
    possible = False
    for i in range(40):
        if gs[i] < Q:
            continue
        elif gs[i] == Q:
            possible = True
            max_g = i + 1
        else:
            break

    if not possible:
        print("Case #{0}: {1}".format(casenum+1, 'impossible'))
        continue

    p = 2
    g = max_g
    while p < P:
        g -= 1
        p = p * 2

    print("Case #{0}: {1}".format(casenum+1, g))
