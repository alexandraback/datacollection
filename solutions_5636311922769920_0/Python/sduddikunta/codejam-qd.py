def extend(t, c, k):
    res = t
    for i in range(1, c):
        res = k*(res - 1) + t
    return res


def main():
    with open('input') as f:
        cases = int(f.readline()[:-1])
        for casen in range(cases):
            case = (int(d) for d in f.readline().split())
            k, c, s = case
            res = []
            for i in range(1, k + 1):
                res.append(extend(i, c, k))
            print("Case #{0}: {1}".format(casen + 1, ' '.join([str(d) for d in res])))


if __name__ == '__main__':
    main()