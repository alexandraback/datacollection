def do_case(case_num, p1, v1, p2, v2):
    if v1 < v2:
        v1, v2 = v2, v1
        p1, p2 = p2, p1
    p1 = -360 + p1
    if v2 * (p2 - p1) < (360 - p2) * (v1 - v2):
        res = 1
    else:
        res = 0
    print "Case #%d: %d" % (case_num, res)

def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        N = int(raw_input())
        if N == 1:
            _ = raw_input()
            print "Case #%d: 0" % case_num
        if N == 2:
            p1, _, v1 = map(int, raw_input().split())
            p2, _, v2 = map(int, raw_input().split())
            do_case(case_num, p1, v1, p2, v2)

if __name__ == "__main__":
    main()
