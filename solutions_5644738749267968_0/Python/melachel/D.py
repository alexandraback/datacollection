n_cases = int(input())

def ken_war(blocks, chosen_naomi):
    try:
        idx = (i for i, x in enumerate(blocks) if x > chosen_naomi).next()
    except StopIteration:
        idx = 0
    return blocks.pop(idx)

def naomi_war(blocks, *args):
    return [blocks.pop(0)] * 2

def naomi_deceitful_war(blocks, ken_blocks, turn):
    try:
        idx = (i for i, x in enumerate(blocks) if x > ken_blocks[0]).next()
        chosen = blocks.pop(idx)
        told = ken_blocks[-1] + 0.0000000001 * turn
    except StopIteration:
        chosen = blocks.pop(0)
        told = ken_blocks[-1] - 0.000001
    return chosen, told

def _naomi_deceitful_war(blocks, ken_blocks):
    if blocks[0] > ken_blocks[-1] or len(blocks) == 1:
        chosen = blocks.pop(len(blocks) - 1)
        return chosen, chosen
    chosen = blocks.pop(0)
    told = ken_blocks[-1] - 0.0000003
    return chosen, told

def play(naomi_strategy, ken_strategy, naomi_blocks, ken_blocks):
    score_naomi = 0
    turn = 1
    while naomi_blocks:
        chosen_naomi, told_naomi = naomi_strategy(naomi_blocks, ken_blocks, turn)
        chosen_ken = ken_strategy(ken_blocks, told_naomi)
        if chosen_naomi > chosen_ken:
            score_naomi += 1
        turn += 1
    return score_naomi

for case in range(0, n_cases):
    _ = input()
    naomi = sorted(float(x) for x in raw_input().split(' '))
    ken = sorted(float(x) for x in raw_input().split(' '))
    
    print "Case #{}: {} {}".format(
        case + 1, 
        play(naomi_deceitful_war, ken_war, list(naomi), list(ken)), 
        play(naomi_war, ken_war, naomi, ken), 
    )
