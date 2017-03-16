#!/usr/bin/env python


def get_input(func):
    raw = raw_input().split(' ')
    return map(func, raw)


def only_a(v, a, t):
    v2 = v + a * t
    return (v + v2) * t / 2.0, v2


def can_catch(v, a, t1, p1, t2, p2, d):
    d = d + p2 - p1
    d2, v = only_a(v, a, t2 - t1)
    delta = d - d2
    if delta > 0:
        return False, delta, v
    else:
        return True, 0, v

def ttt(v, a, s):
    import math
    return (math.sqrt(2 * a * s + v * v) - v) / a

def compute_p(t1, p1, t2, p2, L):
    if p2 == L:
        return t2, p2
    else:
        return (t1 - t2) / (p1 - p2) * L + t1, L


def compute_i(a, tps, L):
    tmp_t, tmp_p = None, None 
    v = 0
    if len(tps) == 1:
        print tps[0][0]
        return
    for t, p in tps:
        if tmp_t == None:
            tmp_t, tmp_p = t, p 
            delta = p
            continue
        if delta == 0 and v > (p - tmp_p) / (t - tmp_t):
            v = (p - tmp_p) / (t - tmp_t)
        if p >= L:
            t, p = compute_p(tmp_t, tmp_p, t, p, L)
            v1 = v
            info, delta, v = can_catch(v, a, tmp_t, tmp_p, t, p, delta)
            if info:
                print t
            else:
                print ttt(v1, a, p - tmp_p) + tmp_t
        else:
            v1 = v
            delta2 = delta
            info, delta, v = can_catch(v, a, tmp_t, tmp_p, t, p, delta)
            if  info:
                tt = t - tmp_t
                ddd = delta2 - v1 * tt
                import math
                v = math.sqrt(2 * ddd / a) + v1
            tmp_t, tmp_p = t, p

def compute(i):
    L, N, A = get_input(float)
    N, A = int(N), int(A)
    tps = []
    print "Case #%d:" % i
    for n in range(N):
        t, p = get_input(float)
        tps.append((t, p))
    allas = get_input(float)
    for a in allas:
        compute_i(a, tps, L)

if __name__ == '__main__':
    i = int(raw_input())
    for x in xrange(i):
        compute(x + 1)
