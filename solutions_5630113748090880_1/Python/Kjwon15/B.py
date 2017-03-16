def solve():
    n = int(input())
    numbers = []
    for _ in range(n * 2 - 1):
        for c in input().split():
            numbers.append(int(c))

    odds = sorted(set(
        number
        for number in numbers
        if numbers.count(number) % 2 == 1
    ))

    return ' '.join(map(str, odds))

round = int(input())
for r in range(1,round+1):
    print('Case #{}: {}'.format(r, solve()))
