def add(poss, x):
    new_poss = set(poss)
    for a in poss:
        new_poss.add(a + x)
    new_poss.add(x)
    return new_poss

def do_case(case_num, c, already, v):
    poss = set([])
    for x in already:
        poss = add(poss, x)
    result = 0
    for x in range(1, v + 1):
        if x not in poss:
            poss = add(poss, x)
            result += 1
    print "Case #%d: %d" % (case_num, result)

t = int(raw_input())
for case_num in range(1, t + 1):
    c, d, v = map(int, raw_input().split())
    already = map(int, raw_input().split())
    do_case(case_num, c, already, v)
