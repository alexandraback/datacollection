import sys
import fractions

def rl(*args):
    return sys.stdin.readline().strip()

def main():
    T = int(rl())
    g = [2**n for n in range(1, 41)]
    p = set(g)
    for c in range(1, T+1):
        P, Q = map(int, rl().split('/'))
        while True:
            gcd = fractions.gcd(P, Q)
            if gcd > 1:
                P = P / gcd
                Q = Q / gcd
                continue
            break
        if Q not in p:
            print 'Case #%d: impossible' % c
        else:
            n = 1
            while n <= P:
                n *= 2
            n /= 2
            r = g.index(Q/n) + 1
            print 'Case #%d: %d' % (c, r)

if __name__ == '__main__':
    main()
