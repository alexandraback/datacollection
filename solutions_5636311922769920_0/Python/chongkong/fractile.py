def number(numbers, base):
    ret = 0
    while len(numbers) > 0:
        ret = (ret * base) + numbers.pop()
    return ret


def positions(k, c, s):
    if k > s * c:
        return 'IMPOSSIBLE'

    pos = []
    # K = 8, C = 3
    # [[0, 1, 2], [3, 4, 5], [6, 7, 0]]
    for i in range((k + c - 1) // c):
        numbers = list(range(c*i, min(c*(i + 1), k)))
        numbers += [0] * (c - len(numbers))
        pos.append(str(number(numbers, k) + 1))

    return ' '.join(pos)


def main():
    case = int(input())
    for i in range(case):
        k, c, s = tuple(input().split())
        k, c, s = int(k), int(c), int(s)
        print('Case #{}: {}'.format(i + 1, positions(k, c, s)))


main()