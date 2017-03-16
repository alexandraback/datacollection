T = input()


def bff():
    N = input()
    s = [int(x) for x in raw_input().strip().split()]
    s.insert(0,0)
    m = {}
    for i in range(1, N + 1):
        m[i] = s[i]
    in_count = [[0,0] for _ in range(N + 1)]
    ans = 0
    for i in range(1, N + 1):
        mark = [0] * (N + 1)
        mark[i] = 1
        p = i
        count = 1
        while mark[m[p]] == 0:
            mark[m[p]] = 1
            count += 1
            if m[m[p]] == i or m[m[p]] == p:
                ans = max(ans, count)
            if m[m[p]] == p and in_count[m[p]][1] < count:
                in_count[m[p]][0] = p
                in_count[m[p]][1] = count
            if p != in_count[m[p]][0]:
                ans = max(ans, count + in_count[m[p]][1] - 1)
            p = m[p]

    return ans



for i in range(1, T + 1):
    print "Case #%d: %d" % (i, bff())