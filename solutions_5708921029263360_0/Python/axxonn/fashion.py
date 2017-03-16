t = int(raw_input())
for case in range(1, t+1):
    j, p, s, k = map(int, raw_input().split(" "))
    combos = []
    for x in range(1, j+1):
        for y in range(1, p+1):
            for z in range(1, s+1):
                combos.append((x, y, z))
    jp = {}
    js = {}
    ps = {}
    answer = []
    for (j_, p_, s_) in combos:
        if (j_, p_) not in jp:
            jp[(j_, p_)] = 0
        if (j_, s_) not in js:
            js[(j_, s_)] = 0
        if (p_, s_) not in ps:
            ps[(p_, s_)] = 0
        if jp[(j_, p_)] == k or js[(j_, s_)] == k or ps[(p_, s_)] == k:
            continue
        jp[(j_, p_)] += 1
        js[(j_, s_)] += 1
        ps[(p_, s_)] += 1
        answer.append(" ".join(map(str, [j_, p_, s_])))
    print "Case #%d: %d" % (case, len(answer))
    for q in answer:
        print q
