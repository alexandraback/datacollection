t = int(input())

for q in range(t):
    k, c, s = map(int, input().split())

    numbers = []

    searching_digit = 0

    while len(numbers) < s and searching_digit < k:
        number = 0

        for digit in range(c):
            number += searching_digit * (k ** digit)
            searching_digit += 1
            if searching_digit == k:
                break

        numbers.append(number + 1)

    if searching_digit < k:
        print('Case #{}: IMPOSSIBLE'.format(q + 1))
    else:
        print('Case #{}: {}'.format(q + 1, ' '.join(map(str, numbers))))
