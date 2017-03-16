cases = input()

def max_i(lst, mi, ma):
    # Slicing costs time
    best = 0
    best_ind = -1
    for i in xrange(mi, ma):
        if lst[i] > best:
            best = lst[i]
            best_ind = i
    return best_ind

def optimal_value(values, max_energy, start, regain, mi, ma, end_ener):
    # END_ENER IS BEFORE THE REGAIN
    #print max_energy, start, regain, mi, ma, end_ener
    # including min, excluding max
    if (mi >= ma):
        return 0
    if (ma - mi == 1):
        ener = start - end_ener
        return values[mi] * ener
    ind = max_i(values, mi, ma)
    # Expend amap on max. How much?
    # Find largest guaranteeable amount of energy before max
    guar = min(max_energy, start + regain * (ind - mi))
    #print 'G %d' % guar
    # min_left = max allowable left before the regain
    min_left = max(0, end_ener - regain * (ma - ind - 1))
    if guar < max_energy:
        score1 = 0
    else:
        score1 = optimal_value(values, max_energy, start, regain, mi, ind, max_energy - regain)
    score2 = (guar - min_left) * values[ind]
    score3 = optimal_value(values, max_energy, min_left + regain, regain, ind + 1, ma, end_ener)
    #print score1 + score2 + score3
    return score1 + score2 + score3

for case in xrange(1, cases + 1):
    e, r, n = [int(t) for t in raw_input().split()]
    values = [int(t) for t in raw_input().split()]
    print "Case #%d: %d" % (case, optimal_value(values, e, e, r, 0, n, 0))