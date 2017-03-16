# @gilesgardam
from itertools import product
infty = float(10**20)
epsilon = 0.0000001
def ints():
    return map(int, raw_input().split())

def intersect(s, p, t, q):
    # find the first time when car (s, p) is 5 behind (t, q)
    # assume s != t
    if p == q - 5:
        return 0.0
    return (p - q + 5) / float(t - s)

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
    N, = ints()
    C = []
    S = []
    P = []
    for i in xrange(N):
        c, s, p = raw_input().split()
        if c == 'L':
            C.append(False)
        elif c == 'R':
            C.append(True)
        else:
            fail = 1 / 0
        S.append(int(s))
        P.append(int(p))

    # lane times for cars
    T = []
    for i in xrange(N):
        T.append([])

    # iterate over all allocation of lanes to all pairs
    cases = [(False, True) for i in xrange((N*(N-1))/2)]
    first_el = {}
    pair_index = 0
    for i in xrange(N):
        for j in xrange(i+1, N):
            first_el[pair_index] = i
            interval = None
            if S[i] == S[j]:
                if abs(P[i] - P[j]) < 5:
                    interval = (0.0, infty)
                else:
                    pass # never intersect
            else:
                ti = intersect(S[i], P[i], S[j], P[j])
                tj = intersect(S[j], P[j], S[i], P[i])
                ti = max(ti, epsilon)
                tj = max(tj, epsilon)
                xx = min(ti, tj)
                yy = max(ti, tj)
                if yy - xx > epsilon:
                    interval = (xx, yy)
            if interval:
                T[i].append((interval, pair_index))
                T[j].append((interval, pair_index))
            pair_index += 1

    for i in xrange(N):
        T[i].sort()


    best_fail_time = -infty
    for case in product(*cases):
        fail_time = infty
        for i in xrange(N):
            times = T[i]
            curr_t = 3*epsilon
            curr_lane = C[i]
            for interval, pair_index in times:
                mask = first_el[pair_index] == i
                lane = mask ^ case[pair_index]
                a, b = interval
                if a + epsilon < curr_t and curr_lane != lane:
                    fail_time = min(fail_time, a)
                curr_t = max(b, curr_t)
                curr_lane = lane
        best_fail_time = max(best_fail_time, fail_time)

    answer = "Possible" if best_fail_time == infty else str(best_fail_time)
    print "Case #%d: %s" % (case_num, answer)
