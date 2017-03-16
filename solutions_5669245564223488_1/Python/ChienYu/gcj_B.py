from sys import stdin

def each_case():
    N = int(stdin.readline())
    cars = stdin.readline().split()
    allsame_sta, head_sta, tail_sta = {}, {}, {}
    forbid = set()
    for i, car in enumerate(cars):
        allsame = True
        head, tail, middle = car[0], car[-1], set()
        last_c = None
        for c in car:
            if c in forbid:
                return 0
            if allsame and c != head:
                allsame = False
                last_c = head
            if not allsame:
                if c == head:
                    return 0
                elif c != last_c and c in middle:
                    return 0
                elif c != tail:
                    middle.add(c)
                last_c = c
        forbid |= middle
        if allsame:
            if head in allsame_sta:
                allsame_sta[head] += 1
            else:
                allsame_sta[head] = 1
        elif head in head_sta or tail in tail_sta:
            return 0
        else:
            head_sta[head] = i
            tail_sta[tail] = i
    ways = 1
    for n in allsame_sta.itervalues():
        for i in xrange(1,1+n):
            ways = (ways*i) % 1000000007
    Nchain = len(set(allsame_sta.keys()) - set(head_sta.keys()) - set(tail_sta.keys()))

    while head_sta:
        findnext = True
        remain = head_sta.keys()
        i = 0
        while findnext:
            if i >= len(remain):
                return 0
            h = remain[i]
            if h in tail_sta:
                i += 1
            else:
                findnext = False
                Nchain += 1
                t = cars[head_sta[h]][-1]
                del head_sta[h]
                while t in head_sta:
                    h = t
                    t = cars[head_sta[h]][-1]
                    del head_sta[h]

    for i in xrange(1,1+Nchain):
        ways = (ways*i) % 1000000007
    return ways

T = int(stdin.readline())
for t in xrange(1,T+1):
    print 'Case #{}: {}'.format(t, each_case())
stdin.close()
