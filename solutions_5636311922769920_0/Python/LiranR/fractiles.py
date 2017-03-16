def list2pos(l, K):
    num = 0
    for digit in l:
        num = num*K + digit
    return num + 1 #because the first tile is #1, not #0


def gen_ans(K, C, S):
    tiles = set()
    cur = 0

    while len(tiles) < S and cur < K:
        tiles.add(list2pos([x%K for x in range(cur, cur+C)], K))
        cur += C

    if cur < K:
        return "IMPOSSIBLE"
    else:
        return " ".join(map(str,tiles))

T = int(raw_input())
for i in xrange(1,T+1):
    K, C, S = map(int, raw_input().split())
    print "Case #%d: %s"%(i, gen_ans(K,C,S))
