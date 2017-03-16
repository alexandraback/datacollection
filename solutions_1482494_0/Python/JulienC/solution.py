def get_k(levels):
    score = 0
    k = 0
    visited = [0] * len(levels)
    levels.sort(reverse=True)
    while levels:
        found = False
        for i in xrange(len(levels)):
            b = levels[i][0]
            if b <= score:
                found = True
                if visited[i] == 0:
                    score += 2
                else:
                    score += 1
                del visited[i]
                del levels[i]
                k += 1
                break
        if not found:
            for i in xrange(len(levels)):
                if visited[i] != 0:
                    continue
                a = levels[i][1]
                if a <= score:
                    found = True
                    visited[i] = 1
                    score += 1
                    k += 1
                    break
        if not found:
            return -1
    return k

def read_file(filename):
    f = open(filename, 'r')
    T = int(f.readline())
    for t in range(T):
        N = int(f.readline())
        levels = list()
        for n in range(N):
            a,b = [int(z) for z in f.readline().split()]
            levels.append((b,a))
        k = get_k(levels)
        if k < 0:
            print 'Case #%d: Too Bad' % (t+1)
        else:
            print 'Case #%d: %d' % (t+1, k)
    f.close()

read_file('B-small-attempt0.in')

