def add_to(s, c, minus):
    merge = s + c
    if s == "":
        return c, minus
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
    S = s*X
    N = L*X
    i_str = ""
    i_minus = False
    i_found = False

    for i in xrange(N-2):
        i_str, i_minus = add_to(i_str, S[i], i_minus)
        if i_str == "i" and not i_minus:
            j_start = i+1
            i_found = True
            break
    if not i_found:
        print "Case #%d: NO" % (T+1, )
        continue
    j_str = ""
    j_minus = False
    j_found = False
    for j in xrange(j_start, N-1):
        j_str, j_minus = add_to(j_str, S[j], j_minus)
        if j_str == "j" and not j_minus:
            k_start = j + 1
            j_found = True
            break
    if not j_found:
        print "Case #%d: NO" % (T+1, )
        continue
    k_str = ""
    k_minus = False
    k_found = False
    for k in xrange(k_start, N):
        k_str, k_minus = add_to(k_str, S[k], k_minus)
        if k_str == "k" and not k_minus:
            one_start = k + 1
            k_found = True
            break
    if not k_found:
        print "Case #%d: NO" % (T+1, )
        continue
    one_str = ""
    one_minus = False
    for o in xrange(one_start, N):
        one_str, one_minus = add_to(one_str, S[o], one_minus)

    if one_str == "" and not one_minus:
        print "Case #%d: YES" % (T+1, )
    else:
        print "Case #%d: NO" % (T+1, )
