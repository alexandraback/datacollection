from dijkstra import f


def find_left(c, m, c_l, m_l):
    for i in xrange(len(c_l)):
        if c_l[i] == c and m_l[i] == m:
            return i
    return -1


def find_right(c, m, c_l, m_l):
    for i in xrange(len(c_l) - 1, -1, -1):
        if c_l[i] == c and m_l[i] == m:
            return i
    return -1


def add_to(s, c, minus):
    merge = s + c
    if s == "":
        return c, minus
    if c == "":
        return s, minus
    if merge in ["ii", "jj", "kk"]:
        return "", not minus
    if merge in ["ik", "ki"]:
        return "j", minus ^ (merge == "ik")
    if merge in ["jk", "kj"]:
        return "i", minus ^ (merge == "kj")
    if merge in ["ij", "ji"]:
        return "k", minus ^ (merge == "ji")


for T in xrange(input()):
    L, X = map(int, raw_input().split(" "))
    s = raw_input()
    if len(set(list(s))) <= 1:
        print "Case #%d: NO" % (T+1, )
        continue
    if X <= 1:
        F = f(s, X, L)
        if F:
            print "Case #%d: YES" % (T+1, )
            continue

    prefix_c = [s[0]]*L
    prefix_m = [False]*L
    suffix_c = [s[-1]]*L
    suffix_m = [False]*L
    repn = 0

    for i in xrange(1, L):
        prefix_c[i], prefix_m[i] = add_to(prefix_c[i-1], s[i], prefix_m[i-1])
        suffix_c[L-1-i], suffix_m[L-1-i] = add_to(s[L-1-i], suffix_c[L-i],
                                                  suffix_m[L-i])

    fc = prefix_c[-1]
    fm = prefix_m[-1]
    i_find = "i"
    i_find_m = False
    j_start = -1
    for i in xrange(4):
        if i != 0:
            i_find, i_find_m = add_to(fc, i_find, i_find_m)
            i_find_m ^= (fm ^ True)
        ind = find_left(i_find, i_find_m, prefix_c, prefix_m)
        if ind != -1:
            j_start = ind + 1
            repn += (i + 1)
            break
    if j_start == -1:
        print "Case #%d: NO" % (T+1, )
        continue
    k_find = "k"
    k_find_m = False
    j_end = -5
    for i in xrange(4):
        if i != 0:
            k_find, k_find_m = add_to(k_find, fc, k_find_m)
            k_find_m ^= (fm ^ True)
        ind = find_right(k_find, k_find_m, suffix_c, suffix_m)
        if ind != -1:
            j_end = ind - 1
            repn += (i + 1)
            break
    if j_end == -5:
        print "Case #%d: NO" % (T+1, )
        continue

    pref = suffix_c[j_start] if j_start < L else ""
    pref_m = suffix_m[j_start] if j_start < L else False
    suff = prefix_c[j_end] if j_end >= 0 else ""
    suff_m = prefix_m[j_end] if j_end >= 0 else False
    j_found = False
    match, match_m = "j", False
    j_match = ""
    j_match_m = False
    for i in xrange(4):
        if i != 0:
            j_match, j_match_m = add_to(j_match, fc, j_match_m)
            j_match_m ^= fm
        j_aug, j_aug_m = add_to(pref, j_match, pref_m)
        j_aug_m ^= j_match_m
        j_aug, j_aug_m = add_to(j_aug, suff, j_aug_m)
        j_aug_m ^= suff_m
        if (j_aug, j_aug_m) == (match, match_m):
            repn += i
            j_found = True
            break
    if not j_found:
        print "Case #%d: NO" % (T+1, )
        continue
    if X >= repn and ((fc, fm) == ("", False) or
                      ((fc, fm) == ("", True) and (X - repn) % 2 == 0) or
                      (X - repn) % 4 == 0):
        print "Case #%d: YES" % (T+1, )
    else:
        print "Case #%d: NO" % (T+1, )
