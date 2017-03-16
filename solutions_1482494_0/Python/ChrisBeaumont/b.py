def solve(onestar, twostar):

    onetwo = zip(onestar, twostar)
    onetwo = sorted(onetwo, key = lambda x: -1 * (x[1] - x[0]))
    onestar, twostar = zip(*onetwo)

    solved = [0] * len(onestar)
    turn = 0
    earned = 0
    while True:
        # can see solve any new two stars?
        moved = False
        for i in range(len(twostar)):
            if earned >= twostar[i] and solved[i] == 0:
                earned += 2
                solved[i] = 2
                moved = True
                break

        if moved:
            turn += 1
            continue

        for i in range(len(twostar)):
            if earned >= twostar[i] and solved[i] == 1:
                earned += 1
                solved[i] = 2
                moved = True
                break

        if moved:
            turn += 1
            continue

        for i in range(len(twostar)):
            if earned >= onestar[i] and solved[i] == 0:
                earned += 1
                solved[i] = 1
                moved = True
                break
        if moved:
            turn += 1
            continue

        # no moves
        break

    if earned == 2 * len(twostar):
        return turn
    return None


def main():
    import sys
    infile = sys.argv[1]

    data = open(infile+'.in').readlines()
    with open(infile+'.out','w') as outfile:
        ntest = int(data[0].strip())
        data = data[1:]

        for i in range(ntest):
            nlevel = int(data[0].strip())
            one, two = [], []
            for j in range(nlevel):
                row = map(int, data[j+1].strip().split())
                one.append(row[0])
                two.append(row[1])
            data = data[nlevel+1:]
            answer = solve(one, two)
            if answer is None:
                anstr = "Case #%i: Too Bad\n" % (i+1)
            else:
                anstr = "Case #%i: %i\n" % (i+1, answer)
            print anstr
            outfile.write(anstr)

def test():
    ones = [0, 0]
    twos = [1, 2]
    print solve(ones, twos)

    ones = [2, 0, 4]
    twos = [2, 0, 4]
    print solve(ones, twos)

    ones = [1]
    twos = [1]
    print solve(ones, twos)

    ones = [0,0,1,4,5]
    twos = [5,1,1,7,6]
    print solve(ones, twos)


if __name__ == "__main__":
    main()