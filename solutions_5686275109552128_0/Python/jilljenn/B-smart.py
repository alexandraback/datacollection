from collections import Counter
SOLS = {}

SENTINEL = -1

def canonical(l):
    return tuple(sorted(l))

def divide(n, k):
    parts = [n / k] * k
    for i in range(n % k):
        parts[i] += 1
    assert sum(parts) == n
    return parts

def best_sol(l, time=0, max_time=1000):
    # print(len(Counter(l)))
    # print(l)
    if time > max_time:
        return float('inf')
    l.sort()
    inst = canonical(l)
    """if inst in SOLS:
        # print('found', inst, SOLS[inst])
        return time + SOLS[inst]"""
    maximum = l.pop()
    best = time + maximum
    if maximum == 1:
        best = time + 1
    else:
        nb_occ = 1
        second_maximum = -1
        while True:
            if not l:
                second_maximum = -1
                break
            second_maximum = l.pop()
            if second_maximum == maximum:
                nb_occ += 1
            else:
                l.append(second_maximum)
                break
        contestants = [(nb_occ + max(2 * maximum / 3, second_maximum), [maximum / 3, maximum - maximum / 3])] if nb_occ == 1 and 2 * maximum / 3 == second_maximum and maximum / 3 > 0 else []
        for k in range(2, maximum + 1):
            parts = divide(maximum, k)
            if maximum == SENTINEL:
                print('->', parts, second_maximum)
            contestants.append((nb_occ * (k - 1) + max(max(parts), second_maximum), parts))
        best_score, _ = min(contestants)
        contestants = filter(lambda x: x[0] <= best_score + 0, contestants)
        if maximum == SENTINEL:
            print(contestants)
            print('%d contestants' % len(contestants))
        for _, parts in contestants:
            sol = best_sol(l + parts * nb_occ, time + nb_occ * (len(parts) - 1))
            # print(sol)
            if sol < best:
                best = sol
                if maximum == SENTINEL:
                    print(best, l + parts)
    SOLS[inst] = best
    return best

T = int(raw_input())
for t in range(T):
    D = int(raw_input())
    P = map(int, raw_input().split())
    print 'Case #%d: %s' % (t + 1, best_sol(P))
# print(len(SOLS))
