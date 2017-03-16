def main():
    cases = int(input())

    for case in range(1, cases + 1):
        n = int(input())
        lists = []

        for i in range(2*n - 1):
            lists.append([int(x) for x in input().split()])

        missing = missing_list(lists)
        out_str = " ".join([str(x) for x in missing])
        print("Case #{0}: {1}".format(case, out_str))


def missing_list(lists):
    mega_list = []
    missing = []

    for l in lists:
        for x in l:
            mega_list.append(x)

    for x in mega_list:
        if ((mega_list.count(x) % 2) != 0) and x not in missing:
            missing.append(x)

    missing.sort()
    return missing


if __name__ == "__main__":
    main()