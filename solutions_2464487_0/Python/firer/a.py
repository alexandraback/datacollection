def paint_needed(r, n):
    rv = n * (2 * r + 1 + 2 * (r + 2 * n - 2) + 1) / 2
    # print "pn", r, n, rv
    return rv


def find_max_n(r, liters, left=0, right=10**20):
    # print "fmn", r, liters, left, right
    if right - left < 10:
        for n in range(left, right + 1):
            if paint_needed(r, n) > liters:
                break
        else:
            raise RuntimeError("something's wrong")
        return n - 1

    mid = (left + right) / 2
    if paint_needed(r, mid) > liters:
        return find_max_n(r, liters, left, mid)
    else:
        return find_max_n(r, liters, mid + 1, right)


def main():
    T = int(raw_input())
    for case_num in range(1, T + 1):
        r, t = map(int, raw_input().split())
        print "Case #{}: {}".format(case_num, find_max_n(r, t))


if __name__ == "__main__":
    import a
    a.main()
