def sheep_count(n):
    if n == 0:
        return 'INSOMNIA'

    remaining_digits = set(range(10))
    for i in range(1, 91):
        current_sheep = str(n * i)
        for ch in current_sheep:
            if int(ch) in remaining_digits:
                remaining_digits.remove(int(ch))
                if len(remaining_digits) == 0:
                    return n*i


def main():
    case = int(input())
    for i in range(case):
        n = int(input())
        print('Case #{}: {}'.format(i+1, sheep_count(n)))


main()
