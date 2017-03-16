__author__ = 'jakub.bibro'


def solve(N):
    D = [i for i in range(0, N + 1)]
    D[0] = 0
    D[1] = 1

    for i in range(2, N + 1):
        reversed_i = reverse(i)
        # print i
        if reversed_i <= i and i == reverse(reversed_i):
            D[i] = min(D[i-1] + 1, D[reversed_i] + 1)
        else:
            D[i] = D[i-1] + 1
        # print D[i]

    return D[N]


def reverse(num):
    return int(str(num)[::-1])


if __name__ == '__main__':
    test_cases = int(raw_input())
    for i in range(0, test_cases):
        N = int(raw_input())
        print('Case #{}: {}'.format(i + 1, solve(N)))
