import sys
n = int(raw_input())

def gcd(a, b):
    while a > 0 and b > 0:
        if a > b: a %= b
        else: b %= a
    if a > 0: return a
    return b

for cas in range(n):
    p, q = map(int, raw_input().split("/"))
    d = gcd(p, q)
    p /= d
    q /= d
    #print p, q

    if ((2 ** 40) % q != 0):
        print ("Case #%d: impossible" % (cas+1))
        continue

    d = (2 ** 40) / q
    p *= d
    q *= d

    best = 0
    for i in range(40):
        if (2 ** i) <= p:
            best = 40 - i

    print ("Case #%d: %d" % (cas+1, best))
