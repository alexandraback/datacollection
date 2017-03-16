def hunt_row(c, w):
    return c // w + w - (c % w == 0)
def fail_row(c, w):
    return c // w + 1 - (c % w == 0)

def do_case(case_num, r, c, w):
    print "Case #%d: %d" % (case_num, hunt_row(c, w) + fail_row(c, w) * (r - 1))

t = int(raw_input())
for case_num in range(1, t + 1):
    r, c, w = map(int, raw_input().split())
    do_case(case_num, r, c, w)
