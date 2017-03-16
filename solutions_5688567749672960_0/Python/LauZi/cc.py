N = 1010101

ans = [0 for _ in range(N)]


def init():
    i = 0
    q = []

    ans[1] = 1
    q.append(1)

    while i < len(q):
        v = q[i]
        i += 1

        cands = [v+1, int(str(v)[::-1])]
        for cand in cands:
            if cand >= N:
                continue
            if ans[cand] != 0:
                continue

            ans[cand] = ans[v] + 1
            q.append(cand)


def main():
    t = input()

    for i in range(1, t+1):
        n = input()
        print "Case #%d: %d" % (i, ans[n])


if __name__ == '__main__':
    init()
    main()