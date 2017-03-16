from itertools import *


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

in_file = open('C-small-attempt2.in', 'r')
out_file = open('out.txt', 'w')

total_case_count = int(in_file.readline())

for i in range(total_case_count):
    print(i)

    max_coins, coin_types, target_value = [int(x) for x in in_file.readline().split()]
    coins = [int(x) for x in in_file.readline().split()]

    init_checked = [False] * (target_value + 1)

    for j in powerset(coins):
        coins_sum = sum(j)

        if coins_sum <= target_value:
            init_checked[coins_sum] = True

    if all(init_checked):
        result = '0'
    else:
        result = ''

    checks = list([[init_checked]])
    depth = 0

    while not result:
        depth += 1
        checks.append([])

        # print(depth)

        for j in checks[depth - 1]:
            if result:
                break

            for k in range(1, target_value + 1):
                new_check = ([False] * k + j)[:target_value + 2]
                new_result = [new_check[l] or j[l] for l in range(target_value + 1)]

                # print(new_result)

                if all(new_result):
                    result = str(depth)
                    # print(new_result)
                    break
                else:
                    checks[depth].append(new_result)

    out_file.write('Case #{}: {}\n'.format(i + 1, result))


in_file.close()
out_file.close()