__author__ = 'arthurnum'


input = open('D-large.in', 'r')
output = open('output.out', 'w')


def deceitful_war(naomi_blocks, ken_blocks):
    score = 0
    while len(naomi_blocks) > 0:
        ken_delta = -1.0
        for x in ken_blocks:
            if (naomi_blocks[0] > x) and (x > ken_delta):
                ken_delta = x
        if ken_delta < 0:
            naomi_blocks.pop(0)
            ken_blocks.remove(max(ken_blocks))
        else:
            naomi_blocks.pop(0)
            ken_blocks.remove(ken_delta)
            score += 1
    return score


def war(naomi_blocks, ken_blocks):
    score = 0
    while len(naomi_blocks) > 0:
        ken_delta = 1.0
        for x in ken_blocks:
            if (naomi_blocks[0] < x) and (x < ken_delta):
                ken_delta = x
        if ken_delta < 1.0:
            naomi_blocks.pop(0)
            ken_blocks.remove(ken_delta)
        else:
            naomi_blocks.pop(0)
            ken_blocks.remove(min(ken_blocks))
            score += 1
    return score


cases = int(input.readline())

for case in range(cases):
    # skip line with N
    input.readline()
    naomi_blocks = [float(x) for x in input.readline().split()]
    ken_blocks = [float(x) for x in input.readline().split()]
    score1 = deceitful_war(list(naomi_blocks), list(ken_blocks))
    score2 = war(list(naomi_blocks), list(ken_blocks))

    output.write("Case #%d: %d %d\n" % (case + 1, score1, score2))