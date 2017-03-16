#!/usr/bin/env python3


def compute_insomnia(v):
    if v == 0: return 'INSOMNIA'
    digs = set()
    num = v
    for _ in range(100):
        digs |= set(str(num))
        if len(digs) == 10: return num
        num += v
    raise Exception('Assumption failed')

def run_test(i):
    v = int(input())
    print('Case #%d: %s' % (i, compute_insomnia(v)))

def main():
    T = int(input())

    for t in range(T):
        run_test(t+1)

def extensive():
    import random
    for i in range(100000):
        compute_insomnia(random.randint(0, 10**6))
    exit(0)

if __name__ == '__main__': main()