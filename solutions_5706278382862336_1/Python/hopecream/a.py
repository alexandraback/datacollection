import sys

def gcd(a, b):
    if a > b:
        a, b = b, a

    if a == 0:
        return b
    else:
        return gcd(a, b % a)

T = int(sys.stdin.readline().strip())

for casei in range(T):
    P, Q = sys.stdin.readline().strip().split('/')
    P = int(P)
    Q = int(Q)

    g = gcd(P, Q)
    P = P / g
    Q = Q / g

    x = Q
    gen = 1
    if (x & x - 1) != 0:
        found = False
    else:
        found = True

        found = True
        while True:
            if gen > 40:
                found = False
                break

            if P >= Q / 2:
                break
            else:
                Q = Q / 2

            gen += 1

    if not found:
        print "Case #{0}: impossible".format(casei + 1)
    else:
        print "Case #{0}: {1}".format(casei + 1, gen)
