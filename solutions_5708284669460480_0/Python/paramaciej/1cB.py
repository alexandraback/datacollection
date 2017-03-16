#!/usr/bin/env python3
import math

EPS = 10 ** -6

T = int(input())

for t in range(1, T + 1):
    k, l, s = (int(x) for x in input().split())
    K = input()
    L = input()

    result = 0.0

    if frozenset([c for c in L]) <= frozenset([c for c in K]):
        ps = [0] + [i for i in range(1, l) if L[:i] == L[-i:]]  # z zerem
        max_occur = math.floor((s - max(ps)) / (l - max(ps)))

        keyboard = frozenset([c for c in K])
        prob = {c: K.count(c) / k for c in keyboard}

        def build(word, occurs, probability):
            if len(word) < s and probability > EPS:
                ret = 0.0
                for c in keyboard:
                    new_word = word + c
                    new_occurs = occurs + (1 if new_word.endswith(L) else 0)
                    new_probability = probability * prob[c]
                    ret += build(new_word, new_occurs, new_probability)
                return ret
            else:
                return occurs * probability

        result = max_occur - build('', 0, 1)

    else:
        result = 0.0

    print("Case #{}: {}".format(t, result))

