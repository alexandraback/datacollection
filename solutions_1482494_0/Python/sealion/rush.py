import sys

inp = sys.stdin


def min_levels(stars, levels, completed1, completed2):
    can_pass_1 = []
    can_pass_2 = []
    if len(completed2) == len(levels):
        return len(completed1) + len(completed2)
    for i, (one, two) in enumerate(levels):
        if i in completed2:
            continue
        if i not in completed1 and one <= stars:
            can_pass_1.append(i)
        if two <= stars:
            can_pass_2.append(i)
    if not can_pass_1 and not can_pass_2:
        return 0
    results = []
    if can_pass_2:
        for i in can_pass_2:
            results.append(min_levels(stars + (2 if i in can_pass_1 else 1), levels, completed1, completed2 + [i]))
    else:
        for i in can_pass_1:
            results.append(min_levels(stars + 1, levels, completed1 + [i], completed2))
    results = filter(None, results)
    if not results:
        return 0
    return min(results)

T = int(inp.readline())
for case_number in range(1, T + 1):
    N = int(inp.readline())
    levels = []
    for i in range(N):
        levels.append(tuple(map(int, inp.readline().split())))
    ml = min_levels(0, levels, [], [])
    if ml:
        print 'Case #%d: %d' % (case_number, ml)
    else:
        print 'Case #%d: Too Bad' % case_number

