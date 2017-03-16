import sys, string

MOD = 1000000007

facts = [1]
for i in xrange(1, 1000):
    facts.append((facts[-1] * i) % MOD)

def check(s):
    seen = set()
    last = None
    for i in s:
        if i != last:
            if i in seen:
                return False
            last = i
            seen.add(i)
    return True

def bf(avail, used, stack, rv):
    if rv[0] > 10000:
        return
    if not check(''.join(stack)):
        return
    if len(stack) == len(avail):
        rv[0] += 1
    else:
        for i, a in enumerate(avail):
            if not used[i]:
                used[i] = True
                stack.append(a)
                bf(avail, used, stack, rv)
                del stack[-1]
                used[i] = False

def solve():
    sys.stdin.readline()
    cars = sys.stdin.readline().split()
    rv = [0]
    bf(cars, [False]*len(cars), [], rv)
    return rv[0]
    dirs = {}
    graph = {}
    graphrev = {}
    isolated = set()
    joining = set()
    for c in cars:
        if isolated & set(c):
            return 0
        head = c[0]
        tail = c[-1]
        isolated |= set(c.lstrip(head).rstrip(tail))
        dir = head + tail
        if not check(c):
            return 0
        joining |= set(dir)
        dirs[dir] = dirs.get(dir, 0) + 1
        if head != tail:
            graph.setdefault(head, []).append(tail)
            graphrev.setdefault(tail, []).append(head)
    ret = 1
    comps = 0
    processed = set()
    for c in joining:
        if len(graphrev.get(c, ())) != 0:
            continue
        cc = c
        while graph.get(cc):
            if cc in processed or len(graph[cc]) > 1:
                return 0
            processed.add(cc)
            ret = (ret * facts[dirs.get(cc+cc, 0)]) % MOD
            cc = graph[cc].pop(0)
        if cc in processed:
            return 0
        processed.add(cc)
        ret = (ret * facts[dirs.get(cc+cc, 0)]) % MOD
        comps += 1
    if len(processed) != len(joining):
        return 0
    #print dirs
    #print 'Components:', comps
    ret = (ret * facts[comps]) % MOD
    return ret

T = int(sys.stdin.readline())
for i in xrange(1, T+1):
    print 'Case #%d:' % i, solve()
    sys.stdout.flush()