def main():
    T = int(input())

    for t in range(1, T + 1):
        n = int(input())
        seen, i = set(), 1
        while len(seen) < 10 and i < 1000:
            s = str(i * n)
            for c in s:
                seen.add(c)
            i += 1

        ret = "INSOMNIA" if len(seen) < 10 else n * (i - 1)
        print("Case #%d: %s" % (t, ret))


if __name__ == '__main__':
    main()
