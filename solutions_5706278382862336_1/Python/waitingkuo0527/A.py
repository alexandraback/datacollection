from fractions import gcd
from math import log2

def solve(P, Q):
    """ solve the problem """

    #print(P, Q)
    g = gcd(P, Q)
    if g > 1:
        P /= g
        Q /= g

    base = 2
    n = 0
    for i in range(1, 42):
        if i == 41: return 'impossible'
        if Q == base ** i: 
            n = i
            break

    count = 1
    base = 1
    while True:
        if P/Q >= 0.49999999: break
        P *= 2
        count += 1
     
    return count


def parse():
    """ parse input """

    P, Q = map(int, input().split('/'))

    return P, Q


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
