from collections import defaultdict
from itertools import product

handsolutions = {
    '3331': [
        '111',
        '122',
        '133',
        '213',
        '221',
        '232',
        '331',
        '312',
        '323',
    ],
    '3332': [
        '111',
        '122',
        '133',
        '113',
        '121',
        '132',
        '211',
        '222',
        '233',
        '231',
        '212',
        '223',
        '313',
        '321',
        '332',
        '331',
        '312',
        '323',
    ],
    '2331': [
        '111',
        '122',
        '133',
        '213',
        '221',
        '232',
    ],
    '1332': [
        '113',
        '121',
        '123',
        '132',
        '112',
        '131',
    ],
    '2332': [
        '113',
        '121',
        '123',
        '132',
        '112',
        '131',
        '213',
        '221',
        '223',
        '232',
        '212',
        '231',
    ],
}

T = int(input())
for I in range(1, T+1):
    result = ""
    j, p, s, k = [int(x) for x in input().split()]
    index = ''.join(str(x) for x in [j,p,s,k])
    if index in handsolutions:
        res = handsolutions[index]
    else:
        options = [range(1, j + 1), range(1, p + 1), range(1, s + 1)]
        wut = list(product(*options))
        res = []
        tupcounter = defaultdict(lambda: 0)

        for a, b, c in wut:
            if tupcounter[(0, 1, a, b)] < k and tupcounter[(1, 2, b, c)] < k and tupcounter[(0, 2, a, c)] < k:
                tupcounter[(0, 1, a, b)] += 1
                tupcounter[(1, 2, b, c)] += 1
                tupcounter[(0, 2, a, c)] += 1
                res.append((a, b, c))

    result = len(res)
    print("Case #%d: %s" % (I, str(result)))
    for t in res:
        print(' '.join(str(x) for x in t))


