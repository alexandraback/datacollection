from math import ceil


def show(i, positions, possible=True):
    if not possible:
        print "Case #%s: IMPOSSIBLE" % (i,)
    else:
        print "Case #%s: %s" % (i, " ".join(map(str, positions)))


def calc_value(fr, K, C):
    ret = 0
    multi = K ** (C - 1)
    while multi > 0 and fr < K:
        ret += fr * multi
        fr += 1
        multi /= K
    return ret + 1, fr


if __name__ == "__main__":
    T = int(raw_input().strip())
    for i in xrange(1, T + 1):
        K, C, S = map(int, raw_input().strip().split())
        if K == 1:
            show(i, [1])
            continue
        if C == 1:
            if S == K:
                show(i, range(1, K + 1))
            else:
                show(i, [], False)
        else:
            limit = int(ceil(float(K) / float(C)))
            if S >= limit:
                curr, sols = 0, []
                while limit > 0:
                    val, curr = calc_value(curr, K, C)
                    sols.append(val)
                    limit -= 1
                show(i, sols)
            else:
                show(i, [], False)
