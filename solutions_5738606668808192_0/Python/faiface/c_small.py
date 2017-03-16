def divisors(n):
    result = []
    i = 2
    while i * i < n:
        if n % i == 0:
            result.append(i)
            break
        i += 1
    return result

t = int(input())

for q in range(t):
    n, j = map(int, input().split())

    print('Case #{}:'.format(q + 1))

    i = 2**(n - 1) + 1
    for _ in range(j):
        while True:
            i_str = bin(i)[2:]
            i += 2

            divs = []

            for d in range(2, 11):
                i_in_d = int(i_str, d)
                divs_d = divisors(i_in_d)
                if len(divs_d) > 0:
                    divs.append(divs_d[0])
                else:
                    break

            if len(divs) == 9:
                print('{} {}'.format(i_str, ' '.join(map(str, divs))))
                break
