def mult(a, b):
    neg = False
    if a[0] == "-":
        neg = not neg
        a = a[1]

    if b[0] == "-":
        neg = not neg
        b = b[1]

    if a == "1":
        res = b
    elif b == "1":
        res = a
    elif a == b:
        res = "1"
        neg = not neg
    else:
        s = "ijkij"
        ind = s.find(a + b)
        if ind == -1:
            neg = not neg
            ind = s.find(b + a)
        res = s[ind + 2]

    if neg:
        return "-" + res
    return res


def get_mod(full_mult):
    if full_mult == "1":
        return 1
    if full_mult == "-1":
        return 2
    return 4


def find_prefix(s, mults_mod):

    cur_mult = mults_mod
    for l in range(0, len(s)):
        if cur_mult == "i":
            return l
        cur_mult = mult(cur_mult, s[l])

    return -1


def find_suffix(s, mults_mod):

    cur_mult = mults_mod
    for start in range(len(s), 0, -1):
        if cur_mult == "k":
            return start
        cur_mult = mult(s[start - 1], cur_mult)

    return -1


def mult_all(s):

    cur_mult = "1"
    for c in s:
        cur_mult = mult(cur_mult, c)

    return cur_mult


def has_no_straddle_solution(L, X, s, full_mult, mults_mod):

    mod = get_mod(full_mult)

    for x in range(4):
        prelen = find_prefix(s, mults_mod[x])
        if prelen == -1:
            continue

        for y in range(4):
            sufstart = find_suffix(s, mults_mod[y])
            if sufstart == -1:
                continue

            if prelen >= sufstart:
                continue

            if mult_all(s[prelen:sufstart]) != "j":
                continue

            trial = X - 1 - x - y
            if trial < 0:
                continue

            if (trial % mod) != 0:
                continue

            return True

    return False


def has_straddle_solution(L, X, s, full_mult, mults_mod):

    mod = get_mod(full_mult)

    for x in range(4):
        prelen = find_prefix(s, mults_mod[x])
        if prelen == -1:
            continue

        for y in range(4):
            sufstart = find_suffix(s, mults_mod[y])
            if sufstart == -1:
                continue

            for z in range(4):

                beg = mult_all(s[prelen:])
                end = mult_all(s[:sufstart])
                mid = mult(beg, mults_mod[z])
                mid = mult(mid, end)

                if mid != "j":
                    continue

                trial = X - 2 - x - y - z
                if trial < 0:
                    continue

                if (trial % mod) != 0:
                    continue

                return True

    return False


T = int(input())

for c in range(1, T + 1):
    L, X = (int(i) for i in input().split())
    s = input()

    full_mult = mult_all(s)

    mults_mod = [None] * 4
    mults_mod[0] = "1"
    for i in range(1, 4):
        mults_mod[i] = mult(mults_mod[i - 1], full_mult)

    if has_no_straddle_solution(L, X, s, full_mult, mults_mod):
        print("Case #{}: YES".format(c))
    elif has_straddle_solution(L, X, s, full_mult, mults_mod):
        print("Case #{}: YES".format(c))
    else:
        print("Case #{}: NO".format(c))
