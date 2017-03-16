def revenge(pancake):
    # print pancake
    length = len(pancake)
    if pancake == '-':
        return 1
    elif pancake == '+':
        return 0
    else:
        if pancake[-1] == '-':
            if pancake[0] == '-':
                return 1 + revenge(flip_pancake(pancake))
            else:
                return 1 + revenge(flip_most_top_happy_pancake(pancake))
        return revenge(pancake[:length-1])


def flip_pancake(pancake):
    result = ''
    for i in range(len(pancake)):
        if pancake[len(pancake) - 1 - i] == '-':
            result += '+'
        else:
            result += '-'
    return result


def flip_most_top_happy_pancake(pancake):
    result = ''
    for i in range(len(pancake)):
        if pancake[i] == '+':
            result += '-'
        else:
            result += pancake[i:]
            return result
    return result


f = open('B-small-attempt0.in')
f1 = open('out.txt', 'wb')
N = f.readline().strip()
i = 1
for line in f.readlines():
    # print line
    f1.write('Case #' + str(i) + ': ' + str(revenge(line.strip())) + '\n')
    i += 1

# print revenge('--++-')