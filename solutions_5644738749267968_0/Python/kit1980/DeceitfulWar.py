def solve(As, Bs):
    n = len(As)
    As.sort()
    Bs.sort()

    d = 0
    i = 0
    j = n - 1
    for a in range(0, n):
        if As[a] > Bs[i]:
            i += 1
            d += 1
        else:
            j -= 1
    w = 0
    i = 0
    j = n - 1
    for a in range(n - 1, -1, -1):
        if As[a] > Bs[j]:
            i += 1
            w += 1
        else:
            j -= 1
    return (d, w)

def do_case(case_num, As, Bs):
    d, w = solve(As, Bs)
    print "Case #%d: %d %d" % (case_num, d, w)

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        n = int(raw_input())
        As = [float(x) for x in raw_input().split()]
        Bs = [float(x) for x in raw_input().split()]
        do_case(case_num, As, Bs)

if __name__ == "__main__":
    main()
