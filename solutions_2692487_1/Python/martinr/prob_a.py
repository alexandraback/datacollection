

f = open(r'e:\downloads\A-large.in', 'r')
#f = open(r'e:\downloads\A-small-attempt2.in', 'r')
#f = open(r'h:\work\python\code_jam\osmos.txt', 'r')

cache = {}

def solve(am, motes):
    global cache

    k = str(am)+' '.join(map(str, motes))
    if k in cache:
        return cache[k]

    if am == 1:
        res = len(motes)
        cache[k] = res
        return res

    if len(motes) == 0:
        res = 0
        cache[k] = res
        return res

    if motes[0] < am:
        res = solve(am+motes[0], motes[1:])
        cache[k] = res
        return res
    else:
        res =  min(solve(am+am-1, motes)+1, solve(am, motes[1:])+1)
        cache[k] = res
        return res

T = int(f.readline())
for t in range(1, T+1):
    amote, n = map(int, f.readline().split())
    motes = map(int, f.readline().split())
    motes.sort()

    print "Case #%d: %d" % (t, solve(amote, motes))


