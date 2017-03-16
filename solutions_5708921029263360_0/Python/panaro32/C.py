#!/usr/bin/env python3

def parse():
    j, p, s, k = map(int, input().split())
    return j, p, s, k

def solve(j, p, s, k):
    n = 0
    w = []
    d = { (('J',ji),('P',pi)) : 0 for ji in range(j) for pi in range(p) }
    d.update( { (('J',ji),('S',si)) : 0 for ji in range(j) for si in range(s) } )
    d.update( { (('P',pi),('S',si)) : 0 for pi in range(p) for si in range(s) } )
    for ji in range(j):
        for pi in range(p):
            for si in range(s):
                if d[(('J',ji),('P',pi))]<k and d[(('J',ji),('S',si))]<k and d[(('P',pi),('S',si))]<k:
                    n += 1
                    w.append('{} {} {}'.format(ji+1, pi+1, si+1))
                    d[(('J',ji),('P',pi))] += 1
                    d[(('J',ji),('S',si))] += 1
                    d[(('P',pi),('S',si))] += 1
    return n, w

def main():
    for i in range(int(input())):
        j, p, s, k = parse()
        n, w = solve(j, p, s, k)
        print('Case #{}: {}'.format(i+1, n))
        print('\n'.join(w))

if __name__ == '__main__': main()
