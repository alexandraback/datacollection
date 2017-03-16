import sys


# Naomi plays largest cards, and ken counters with smallest cards
# unless his largest card is larger than naomi's in which case
# he takes the point
def fair_war(naomi, ken):
    naomi_hi, ken_hi = len(naomi) - 1, len(ken) - 1
    n_score = 0
    for i in range(0, len(naomi)):
        if naomi[naomi_hi] > ken[ken_hi]:
            n_score += 1
        else:
            ken_hi -= 1
        naomi_hi -= 1
    return n_score


# Naomi plays largest cards, and ken counters with smallest cards
# unless his largest card is larger - in which case Naomi plays her
# smallest card and 'wastes' ken's largest card
def deceitful_war(naomi, ken):
    naomi_lo, ken_lo = 0, 0
    n_score = 0
    for i in range(0, len(naomi)):
        # naomi can score by lying and telling ken her
        # card is > ken[-1], thus ken plays his low card
        # and naomi scores
        if naomi[naomi_lo] > ken[ken_lo]:
            n_score += 1
            ken_lo += 1
        # else she can lie and get ken to play his hi
        # card. No matter what, naomi uses her low cards
        # sequentially
        naomi_lo += 1
    return n_score


num_cases = int(sys.stdin.readline())
for case in range(1, num_cases + 1):
    N = int(sys.stdin.readline())
    naomi = list(map(float, sys.stdin.readline().split()))
    naomi.sort()
    ken = list(map(float, sys.stdin.readline().split()))
    ken.sort()
    s1 = deceitful_war(naomi, ken)
    s2 = fair_war(naomi, ken)
    print("Case #" + str(case) + ": {} {}".format(s1, s2))
