def main():
    with open('input') as f:
        cases = int(f.readline()[:-1])
        for casen in range(cases):
            case = int(f.readline()[:-1])
            if case == 0:
                print("Case #{0}: INSOMNIA".format(casen + 1))
                continue
            i = 0
            seen = [False, False, False, False, False, False, False, False, False, False]
            while True:
                i += 1
                for c in str(case * i):
                    seen[int(c)] = True
                ok = True
                for k in seen:
                    if not k:
                        ok = False
                if ok:
                    print("Case #{0}: {1}".format(casen + 1, case * i))
                    break


if __name__ == '__main__':
    main()