def flip(stack, end):
    flipped = ''
    for k in range(end, -1, -1):
        flipped += '+' if stack[k] == '-' else '-'
    return flipped


def main():
    with open('input') as f:
        cases = int(f.readline()[:-1])
        for casen in range(cases):
            case = f.readline()[:-1]

            flips = 0
            processing = True
            while processing:
                minus = False
                for i in range(len(case)):
                    pancake = case[i]
                    if not minus and pancake == '-':
                        minus = True
                        if i > 0:
                            case = flip(case, i - 1) + case[i + 1:]
                            flips += 1
                            break
                    if minus and pancake == '+':
                        case = flip(case, i - 1) + case[i + 1:]
                        flips += 1
                        break
                    if minus and i == len(case) - 1:
                        case = flip(case, i) + case[i + 1:]
                        flips += 1
                        break
                if not minus:
                    processing = False
            print("Case #{0}: {1}".format(casen + 1, flips))


if __name__ == '__main__':
    main()