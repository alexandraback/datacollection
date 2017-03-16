import math


def solve(r, t):
    a = 2
    b = 2*r -1
    c = -t
    sol = solvequad(a, b, c)
    floorsol = int(math.floor(sol))
    if paintneeded(r, floorsol) <= t:
        return floorsol
    else:
        return floorsol-1


def solvequad(a, b, c):
    discRoot = math.sqrt((b * b) - 4 * a * c) # first pass
    root1 = (-b + discRoot) / (2 * a) # solving positive
    #root2 = (-b - discRoot) / (2 * a) # solving negative
    return root1

def paintneeded(r, n):
    return n*(2*n-1+2*r)


inp = raw_input()
T = int(inp)
for i in range(1,T+1):
    inp = raw_input()
    r, t = map(int, inp.split(' '))
    answer = solve(r, t)
    print "Case #" + str(i) + ": " + str(answer)
