def solve(hikers):
    min_enc = len(hikers)
    for _, total_m in hikers:
        encounter = 0
        for d, now_m in hikers:
            rest_time = (360 - d) * now_m / 360.0
            if rest_time > total_m:
                encounter += 1
            else:
                encounter += int((total_m - rest_time) / now_m)
        min_enc = min(encounter, min_enc)
    return min_enc

T = input()
for t in range(T):
    n = input()
    hikers = []
    for _ in range(n):
        d, h, m = map(int, raw_input().split())
        for dm in range(h):
            hikers.append((d, m + dm))
    result = solve(hikers)
    print 'Case #%d: %d' % (t + 1, result)
