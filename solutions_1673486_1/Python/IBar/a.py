import sys

T = int(sys.stdin.readline())

for i in range(T):
    one = sys.stdin.readline()
    one = one.split()
    a = int(one[0])
    b = int(one[1])
    p = sys.stdin.readline()
    p = p.split()
    p = list(map(lambda x: float(x), p))
    best = b+2
    no_errors = 1
    for idx, pi in enumerate(p):
        no_errors = no_errors * pi
        bs_cost = (a - (idx+1))*2 + 1 + (b-a)
        was_error_cost = b+1
        expected = no_errors * bs_cost + (1-no_errors) * (was_error_cost + bs_cost)
        if expected < best:
            best = expected
    print("Case #%s: %.6f" % (str(i+1),best))
