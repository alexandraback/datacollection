#!/usr/bin/python

def main():
    with open("A-small-attempt0.in") as f:
        T = int(f.readline().strip())

        for Tcur in range(1, T+1):
            (A, B) = [int(x) for x in f.readline().strip().split()]
            p = [float(x) for x in f.readline().strip().split()]

            k1 = kcont(A, B, p)
            k2 = kenter(A, B, p)

            kb = kback(A, B, 0, p)
            for i in range(1, A):
                tmp = kback(A, B, i, p)
                if tmp < kb:
                    kb = tmp

            k = min(k1, k2, kb)
            
            print "Case #%d: %f" % (Tcur, k)

        f.close()

def foo(args):
    return args

def kcont(typed, tot, p):
    return tot - typed + (tot+1)*(1 - pi(p, typed)) + 1;

def kback(typed, tot, back, p):
    return tot - typed + 2*back + (tot+1)*(1 - pi(p, typed-back)) + 1

def kenter(typed, tot, p):
    return 2 + tot

def pi(p, n):
    res = 1
    for i in range(n):
        res *= p[i]
    return res

if __name__=="__main__":
    main()
