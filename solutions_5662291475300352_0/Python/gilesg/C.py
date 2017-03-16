def ints():
    return map(int, raw_input().split())

num_cases, = ints()

def lap_finish_time(h, i):
    # time it takes to finish i-th lap
    d, m = h
    return (360 * i - d) * m

def solve(hikers):
    L = len(hikers)
    if L > 2:
        raise ValueError("too hard!")
    if L < 1:
        raise ValueError("wtf!")
    if len(hikers) == 1:
        return 0

    hikers.sort()
    if hikers[0][0] == hikers[1][0]: # start same place
        hikers = hikers[::-1] # put slower guy in position 1

    if lap_finish_time(hikers[0], 1) < lap_finish_time(hikers[1], 2) and lap_finish_time(hikers[1], 1) < lap_finish_time(hikers[0], 2):
        return 0 # can coast between them
    return 1 # bad luck Herbert!

for case_num in xrange(1, num_cases + 1):
    hikers = []
    N, = ints()
    for h in range(N):
        D, H, M = ints()
        for i in range(H):
            hikers.append((D, M+i))
    ans = solve(hikers)
    print "Case #%d: %d" % (case_num, ans)
