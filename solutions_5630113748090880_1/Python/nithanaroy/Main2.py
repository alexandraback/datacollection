def solve_test_case(case):
    d = {}
    n = int(raw_input())
    i = 0
    while i < 2 * n - 1:
        l = map(int, raw_input().split(" "))
        for num in l:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        i += 1
    res = []
    for key in d.keys():
        if d[key] % 2 != 0:
            res.append(key)
    print "Case #%d: %s" % (case, ' '.join(map(str, sorted(res))))


def main():
    t = int(raw_input())
    i = 1
    while t > 0:
        solve_test_case(i)
        t -= 1
        i += 1


if __name__ == '__main__':
    main()
