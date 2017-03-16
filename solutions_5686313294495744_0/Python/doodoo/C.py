import itertools

def calc(first_words, second_words, words, perm):
    first = first_words.copy()
    second = second_words.copy()

    res = 0
    for i in perm:
        w1, w2 = words[i]

        if w1 in first and w2 in second:
            res += 1

        first.add(w1)
        second.add(w2)

    return res

def solve(words):
    first = {}
    second = {}

    for w1, w2 in words:
        first[w1] = first.get(w1, 0) + 1
        second[w2] = second.get(w2, 0) + 1

    first_words = set()
    second_words = set()

    new_words = []
    for w1, w2 in words:
        if first[w1] < 2 or second[w2] < 2:
            first_words.add(w1)
            second_words.add(w2)
            continue
        new_words.append((w1, w2))

    words = new_words
    N = len(words)

    all_left = set()
    all_right = set()
    for w1, w2 in words:
        if w1 not in first_words:
            all_left.add(w1)
        if w2 not in second_words:
            all_right.add(w2)

    ret = 0
    for i in xrange(0, N):
        for comb in itertools.combinations(words, i):
            w_left = set()
            w_right = set()
            for w1, w2 in comb:
                w_left.add(w1)
                w_right.add(w2)

            if all_left.issubset(w_left) and all_right.issubset(w_right):
                return N - i

    return ret

    # ret = 0

    # new_words2 = []
    # for w1, w2 in new_words:
    #     if w1 not in first_words and w2 not in second_words:
    #         first_words.add(w1)
    #         second_words.add(w2)
    #         continue
    #     new_words2.append((w1, w2))

    # ret = 0
    # new_words3 = []
    # for w1, w2 in new_words2:
    #     if w1 not in first_words or w2 not in second_words:
    #         first_words.add(w1)
    #         second_words.add(w2)
    #         continue
    #     ret += 1

    # return ret

T = int(raw_input())

for i in xrange(T):
    N = int(raw_input())
    words = []
    for j in xrange(N):
        s, t = raw_input().split()
        words.append((s, t))

    print 'Case #%d: %d' % (i + 1, solve(words))
