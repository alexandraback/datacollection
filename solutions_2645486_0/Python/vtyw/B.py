realbest = 0

def solve(acts, en, ind, total, E, R):
    global realbest
    #print "ind", ind
    if ind >= len(acts):
        if total > realbest:
            realbest = total
        return total
    best = 0
    for e in xrange(en + 1):
        score = solve(acts, min(E, en - e + R), ind + 1, total + acts[ind] * e, E, R)
        if score > best:
            best = score
    return best


T = int(raw_input())
for t in xrange(T):
    E, R, N = [int(x) for x in raw_input().split()]
    
    acts = [int(x) for x in raw_input().split()]
    realbest *= 0
    ans = solve(acts, E, 0, 0, E, R)
    print "Case #%d: %d" % (t + 1, realbest)
    #print realbest