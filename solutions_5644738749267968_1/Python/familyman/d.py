"""
optimal strategy:
    when naomi presents a block of mass chosen_naomi

    if there are blocks with w > chosen_naomi
        smack out the smallest of these ones

    otherwise
        smack out the smallest block there is

cheat:
    get rid of larger blocks

    if naomi says x
        and ken can match it with y
            he will play y
            naomi should then play _smallest_
            this will give ken one point
        otherwise
            he will play $smallest
            naomi should then play her first that is larger than $smallest


    cheap options:
        if ken_max > naomi_max:
            this will win for ken anyway
            "cheat high"
            say $ken_max - 1E12 // don't need to compute this ofc

        if x > ken_max and naomi has y > ken_min:
            this will win for naomi
            ken plays $ken_min
            naomi plays first > $ken_min


naomi: 11 8  7 4 3 1
ken:   14 10 9 8 4 2


if max(ken) > max(naomi):
    # should cheat
    # point for ken anyways
    # "say" max(ken) - eps
    ken -= max(ken)
    naomi -= min(naomi)

elif any(y > min(ken) for y in naomi):
    y = -1
    for yy in naomi:
        if yy > min(ken) and (y == -1 or yy < y):
            y == yy

    # "say" max(ken)+eps
    ken -= min(ken)
    naomi -= y
    pts_naomi += 1

"""


import sys

_input = sys.stdin.read().split()[::-1]
I = lambda: int(_input.pop())
D = lambda: float(_input.pop())


def find_smallest_larger(seq, x):
    y = None
    for yy in seq:
        if yy > x and (y is None or yy < y):
            y = yy
    return y


def deceitful_war(_naomi, _ken):
    naomi, ken = set(_naomi), set(_ken)
    pts_naomi = 0

    while naomi:
        if max(naomi) > max(ken):
            # say max(naomi)
            y = min(ken)
            x = find_smallest_larger(naomi, y)
            assert not x is None
        else:
            assert max(ken) > max(naomi)
            # say max(ken)-eps
            y = max(ken)
            x = min(naomi)

        naomi.remove(x)
        ken.remove(y)
        if x > y:
            pts_naomi += 1

    return pts_naomi


def war(_naomi, _ken):
    naomi, ken = set(_naomi), set(_ken)
    pts_naomi = 0

    for x in list(naomi):
        y = find_smallest_larger(ken, x)
        if y is None:
            y = min(ken)

        naomi.remove(x)
        ken.remove(y)

        if x > y:
            pts_naomi += 1

    return pts_naomi


for t in range(1, I()+1):
    N = I()

    naomi = [D() for i in range(N)]
    ken = [D() for i in range(N)]

    print 'Case #%d: %d %d' % (
            t,
            deceitful_war(naomi, ken),
            war(naomi, ken),)
