case_number = 0

def output(ans1, ans2):
    global case_number
    case_number += 1
    print "Case #{0}: {1} {2}".format(case_number, ans1, ans2)

def count_treat():
    global naomi, ken
    t_naomi = sorted(naomi)
    t_ken = sorted(ken)
    res = 0
    while len(t_naomi) > 0:
        if t_naomi[0] > t_ken[0]:
            res += 1
            t_naomi = t_naomi[1:]
            t_ken = t_ken[1:]
        else:
            t_naomi = t_naomi[1:]
            t_ken = t_ken[:-1]
    return res

def find_min_larger(ls, n):
    lp = 0
    rp = len(ls) - 1
    while lp < rp:
        mid = (lp + rp + 1) / 2
        if ls[mid] >= n:
            lp = mid
        else:
            rp = mid - 1;
    return lp;

def count_normal():
    global naomi, ken
    t_naomi = sorted(naomi, reverse = True)
    t_ken = sorted(ken, reverse = True)
    res = 0
    while len(t_naomi) > 0:
        if t_naomi[0] > t_ken[0]:
            res += 1
            t_naomi = t_naomi[1:]
            t_ken = t_ken[:-1]
        else:
            p = find_min_larger(t_ken, t_naomi[0])
            t_naomi = t_naomi[1:]
            t_ken = t_ken[0:p] + t_ken[p + 1:]

    return res

if __name__ == "__main__":
    T = input()
    while T > 0:
        T -= 1
        input()
        naomi = map(float, raw_input().split())
        ken = map(float, raw_input().split())
        treat = count_treat()
        normal = count_normal()
        output(treat, normal)
