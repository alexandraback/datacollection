import math
import random

full_proof_lim = 100
rand_proof_count = 100

def main():
    random.seed(1)
    t = int(raw_input())
    for i in xrange(t):
        n, j = map(int, raw_input().split(" "))
        found = set([])
        print "Case #%d:" % (i + 1)
        while len(found) < j:
            s = gen(n)
            if s not in found:
                ps = proveAll(s)
                if ps is not None:
                    found.add(s)
                    print s, ' '.join(map(str, ps))

def proveAll(s):
    ps = []
    for b in xrange(2, 11):
        p = prove(int(s, b))
        if p is None:
            return None
        ps.append(p)
    return ps

def prove(n):
    if n % 2 == 0:
        if n == 2:
            return None
        return 2
    root = int(math.sqrt(n))
    upper_bound = min(root, full_proof_lim)
    for i in xrange(3, upper_bound + 1, 2):
        if n % i == 0:
            return i
    for i in xrange(rand_proof_count):
        d = random.randrange(3, root + 1)
        if n % d == 0:
            return d
    return None

def gen(n):
    s = []
    s.append('1')
    for i in xrange(n - 2):
        s.append(random.choice('01'))
    s.append('1')
    return ''.join(s)

if __name__ == "__main__":
    main()
