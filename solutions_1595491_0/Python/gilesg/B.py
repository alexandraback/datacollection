non_sup_deltas = [(0, 0, 0), (1, 0, 0), (1, 1, 0)]
sup_deltas = [(1, 0, -1), (1, 0, 0), (2, 0, 0)]
short_circuit = {
        0 : (0, 0, 0),
        29 : (10, 10, 9),
        30 : (10, 10, 10)
}

def best(total, deltas):
    if total in short_circuit:
        return short_circuit[total]
    return tuple(total / 3 + deltas[total % 3][i] for i in xrange(3))

T = int(raw_input())
for case_num in xrange(1, T + 1):
    ints = map(int, raw_input().split())
    N, S, p = ints[:3]
    totals = ints[3:]
    count = 0
    for total in totals:
        if max(best(total, non_sup_deltas)) >= p:
            count += 1
        elif max(best(total, sup_deltas)) >= p and S > 0:
            count += 1
            S -= 1
    print "Case #%d: %d" % (case_num, count)
