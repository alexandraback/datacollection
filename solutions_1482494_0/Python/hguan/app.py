import sys

def do_case(k):
    f = sys.stdin
    line = f.readline()
    n = int(line.strip())
    levels = []
    for i in xrange(n):
        line = f.readline()
        a = int(line.strip().split(' ')[0])
        b = int(line.strip().split(' ')[1])
        levels.append([2, a, b])

    p = 0
    t = 0
    last_t = t
    while True:
        # choose level
        # choose level with 2 stars and we can solve it now
        candidates = filter(lambda i: levels[i][0] == 2 and levels[i][2] <= p, xrange(n))
        t += len(candidates)
        p += 2 * len(candidates)
        for i in candidates:
            levels[i][0] = 0 # mark solved
        if len(candidates) > 0:
            continue
        # choose levels with 1 star left
        candidates = filter(lambda i: levels[i][0] == 1 and levels[i][2] <= p, xrange(n))
        t += len(candidates)
        p += len(candidates)
        for i in candidates:
            levels[i][0] = 0 # mark solved
        if len(candidates) > 0:
            continue
        # choose levels with 2 stars, but we can only get 1 star now
        candidates = filter(lambda i: levels[i][0] == 2 and levels[i][1] <= p, xrange(n))
        if len(candidates) > 0:
            # find the one hardest one?
            max_b = -1
            max_i = 0
            for i in candidates:
                if max_b < levels[i][2]:
                    max_b = levels[i][2]
                    max_i = i
            t += 1
            p += 1
            levels[max_i][0] = 1 # got star
            continue
        if last_t == t:
            break
        last_t = t
        if p == 2 * n:
            print 'Case #%d: %d' % (k, t)
            return
    print 'Case #%d: Too Bad' % k

def main():
    f = sys.stdin
    line = f.readline()
    T = int(line.strip())
    for i in xrange(T):
        do_case(i + 1)

if __name__ == '__main__':
    main()