def read_number(f):
    return int(f.readline().strip())


def read_list(f):
    return list(map(int, f.readline().split()))


def compute(pancakes):
    best = max(pancakes)

    def recursive(pancakes, time, best):
        best = min(best, time + max(pancakes))

        if max(pancakes) <= 3:
            return best

        most = max(pancakes)
        idx = pancakes.index(most)

        for i in range(2, most//2 + 1):
            pancakes2 = pancakes[:]
            pancakes2[idx] = i
            pancakes2.append(most - i)
            best = recursive(pancakes2, time + 1, best)

        return best

    return recursive(pancakes, 0, max(pancakes))


def main():
    with open('B-small-attempt2.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            people_count = read_number(f)
            pancakes = read_list(f)
            output = compute(pancakes)
            print('Case #{}: {}'.format(test_case + 1, output))

if __name__ == '__main__':
    main()
