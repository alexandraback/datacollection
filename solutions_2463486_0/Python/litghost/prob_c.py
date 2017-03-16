import gmpy

def read_problem(f):
    itr = iter(f)
    T = int(itr.next())

    for _ in xrange(T):
        yield map(gmpy.mpz, itr.next().strip().split())

def ispall(v):
    sv = str(v)

    return sv == sv[-1::-1]

def count_fair(low, high):
    count = 0
    for v in xrange(gmpy.sqrt(low)-1, gmpy.sqrt(high)+1):
        sqv = v**2
        if sqv < low:
            continue

        if sqv > high:
            continue

        if not ispall(v):
            continue

        if ispall(sqv):
            count += 1

    return count

def main():
    import sys
    with open(sys.argv[1]) as f:
        for case, (low, high) in enumerate(read_problem(f)):
            print 'Case #%d: %d' % (case+1, count_fair(low, high))

if __name__ == '__main__':
    main()
