import itertools

data = open("input/problema.txt")
nb_cases = int(data.readline())

def countNb(letters, target):
    count = 0
    len_target = len(target)
    for start in xrange(len(letters) - len_target + 1):
        ok = True
        for j in xrange(len_target):
            if letters[start+j] != target[j]:
                ok = False
                break
        if ok:
            count += 1
    return count

def test():
    K, L, S = [int(x) for x in data.readline().split(" ")]
    letters = data.readline().rstrip('\n')
    # letters = [letters[i] + str(i) for i in xrange(len(letters))]
    word = [x for x in data.readline().rstrip('\n')]

    # if S < L:
    #     return 0
    #
    # for l in word:
    #     if l not in letters:
    #         return 0

    combinations = itertools.product(letters, repeat=S)
    max_count = 0
    total = 0
    n = 0
    for comb in combinations:
        count = countNb([x[0] for x in comb], word)
        total += count
        max_count = max(max_count, count)
        n += 1
    return float(max_count) - float(total) / n


for z in xrange(nb_cases):
    print "Case #%d:" % (z + 1),
    print test()


