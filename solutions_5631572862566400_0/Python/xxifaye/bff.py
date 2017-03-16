import sys

def solve():

    def find_t():
        t = set()
        for i in bff:
            if i in set():
                continue
            f = bff[i]
            if bff[f] == i:
                t.add(i)
                t.add(f)
        return t

    n = int(sys.stdin.readline())
    ret = 0
    bff = map(int, sys.stdin.readline().split())
    bff = [i-1 for i in bff]
    tuan = find_t()
    tuan_s = len(tuan)
    max_s = []
    for l in xrange(n):
        if l in tuan:
            continue
        c = [l]
        while True:
            f = bff[c[-1]]
            if f in tuan:
                c = c + [-2]*tuan_s
                break
            if f == c[0]:
                break
            if f in c:
                c = []
                break
            c.append(f)
        if -2 in c:
            max_s.append(set(c) - set([-2]))
        ret = max(ret, len(c))
    if not max_s:
        return ret

    max_s.sort(key=len, reverse=True)
    maxx = max_s[0]
    for i in max_s[1:]:
        if maxx.intersection(i):
            continue
        else:
            return len(maxx) + len(i) + tuan_s
    return len(maxx) +tuan_s

if __name__ == '__main__':
    c = int(sys.stdin.readline())
    for i in xrange(c):
        print 'Case #%s: %s' % (i + 1, solve())
