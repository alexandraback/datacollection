def compute(hikers_unfattened):
    hikers = []

    for D, H, M in hikers_unfattened:
        for M in range(M, M+H):
            hikers.append((D, M))


    #print(hikers)

    if len(hikers) < 2:
        return 0
    else: # len(hikers) == 2
        # find first hiker
        hikers.sort(key=lambda hiker: -hiker[1])
        # go immediately to the slower hiker
        to_go = 360 - hikers[0][0]

        # calculate the time this hiker needs for completing the run
        time_left = to_go * hikers[0][1] / 360
        # where is the other hiker at this moment?
        pos_hiker2 = hikers[1][0] + (time_left / hikers[1][1])*360
        if pos_hiker2 >= 720:
            return 1
        else:
            return 0


def read_number(f):
    return int(f.readline().strip())


def read_numbers(f):
    return list(map(int, f.readline().strip().split()))


def main():
    with open('C-small-1-attempt1.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            N = read_number(f)
            hiker = []
            for _ in range(N):
                hiker.append(read_numbers(f))
            print('Case #{}: {}'.format(test_case + 1, compute(hiker)))


if __name__ == '__main__':
    main()