def simulate(c, f, x, k):
    r = 2.0
    t = 0.0
    for i in range(k):
        t += c / r
        r += f
    t += x / r
    return t

def fid_min(c, f, x):
    lo = 0
    hi = int(x / c) + 10
    while lo < hi:
        mid = 1 + (lo + hi) // 2
        tprev = simulate(c, f, x, mid - 1)
        tcurr = simulate(c, f, x, mid)
        if tprev > tcurr:
            lo = mid
        else:
            hi = mid - 1
    return simulate(c, f, x, lo)

def do_case(case_num, c, f, x):
    min_t = fid_min(c, f, x)
    print "Case #%d: %.7f" % (case_num, min_t)

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        c, f, x = map(float, raw_input().split())
        do_case(case_num, c, f, x)

if __name__ == "__main__":
    main()
