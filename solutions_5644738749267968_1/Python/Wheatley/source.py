import heapq as hq


def fair_optimum(n_blocks, k_blocks):
    n_blocks = list(n_blocks)
    k_blocks = list(k_blocks)
    hq.heapify(n_blocks)
    hq.heapify(k_blocks)

    score = 0
    while not k_blocks == []:
        if k_blocks[0] > n_blocks[0]:
            hq.heappop(n_blocks)
        else:
            score += 1
        hq.heappop(k_blocks)
    return score


def deceitful_optimum(n_blocks, k_blocks):
    return len(n_blocks) - fair_optimum(k_blocks, n_blocks)


with open('input') as in_file:
    with open('output', 'w') as out_file:
        number_cases = int(in_file.readline())

        for case in range(number_cases):
            in_file.readline()
            n_blocks = list(map(float, in_file.readline().split()))
            k_blocks = list(map(float, in_file.readline().split()))

            out_file.write('Case #{}: {} {}\n'.format(case + 1,
                    deceitful_optimum(n_blocks, k_blocks),
                    fair_optimum(n_blocks, k_blocks)))
