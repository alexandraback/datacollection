# Python 3.2
# Usage: python b.py < input.in > out.txt

cases = int(input())
for case in range(cases):
    inp = list(int(i) for i in input().split())
    N, S, p = inp[0], inp[1], inp[2]
    ts = inp[3:]
    defs, poss = 0, 0
    for t in ts:
        if t >= 28:
            defs += 1
        elif t == 0:
            if p == 0:
                defs += 1
        elif t > (p-1)*3:
            defs += 1
        elif t > (p-1)*3 - 2:
            poss += 1
    if poss <= S:
        defs += poss
    else:
        defs += S
    print("Case #{}: {}".format(case + 1, defs))
