from sys import stdin, stdout

def binary_search(blocks, min_index, max_index, indicator):
    if (min_index >= max_index):
        return min_index
    mid_index = int((min_index + max_index) / 2)
    if blocks[mid_index] < indicator:
        return binary_search(blocks, mid_index + 1, max_index, indicator)
    else:
        return binary_search(blocks, min_index, mid_index - 1, indicator)

def find_least_block_not_less_than(blocks, indicator):
    index = binary_search(blocks, 0, len(blocks) - 1, indicator)
    while index < len(blocks) and blocks[index] < indicator:
        index += 1
    index_beta = index
    while index_beta < len(blocks) and blocks[index_beta] == indicator:
        index_beta += 1
    if index_beta < len(blocks):
        return index_beta
    else:
        return index

def get_war_score(N, naomi_blocks, ken_blocks):
    score = 0
    ken_blocks = sorted(ken_blocks)
    for block in naomi_blocks:
        decision_index = find_least_block_not_less_than(ken_blocks, block)
        if decision_index >= len(ken_blocks):
            decision_index = 0
        if ken_blocks[decision_index] < block:
            score += 1
        del ken_blocks[decision_index]
    return score

def find_least_block_greater_than(blocks, indicator):
    index = binary_search(blocks, 0, len(blocks) - 1, indicator)
    while index < len(blocks) and blocks[index] < indicator:
        index += 1
    while index < len(blocks) and blocks[index] == indicator:
        index += 1
    return index

def get_deceitful_score(N, naomi_blocks, ken_blocks):
    score = 0
    ken_blocks = sorted(ken_blocks)
    naomi_blocks = sorted(naomi_blocks)
    for block in ken_blocks:
        decision_index = find_least_block_greater_than(naomi_blocks, block)
        if decision_index >= len(naomi_blocks):
            decision_index = 0
        if naomi_blocks[decision_index] > block:
            score += 1
        del naomi_blocks[decision_index]
    return score


T = int(stdin.readline())

for i in xrange(1, T + 1):
    N = int(stdin.readline())
    args = stdin.readline().strip().split(' ')
    naomi_blocks = [float(block) for block in args][:N]
    args = stdin.readline().strip().split(' ')
    ken_blocks = [float(block) for block in args][:N]
    deceitful_score = get_deceitful_score(N, naomi_blocks, ken_blocks)
    war_score = get_war_score(N, naomi_blocks, ken_blocks)
    stdout.write('Case #%d: %d %d\n' % (i, deceitful_score, war_score))