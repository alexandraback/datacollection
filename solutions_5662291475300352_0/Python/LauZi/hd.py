def jizz():
    n = input()

    ds = []
    for _ in range(n):
        [d, hh, m] = map(int, raw_input().split())
        for h in range(hh):
            ds.append((d, 1/float(m+h)))

    if len(ds) < 2:
        return 0

    ds.sort()

    t = float(360 - ds[0][0]) / ds[0][1]
    xp = t * ds[1][1] + ds[1][0]

    if xp >= 720 or ds[0][0] == 0:
        return 1

    return 0


def main():
    tt = input()

    for t in range(1, tt+1):
        print 'Case #%d: %d' % (t, jizz())


if __name__ == '__main__':
    main()