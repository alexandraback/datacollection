#!/usr/bin/env python

def memoize(func):
    cache = {}
    @wraps(func)
    def wrap(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]
    return wrap


def read_ints():
    return [int(x) for x in input().split()]

T = int(input())

R, N, M, K = read_ints()

print("Case #1:", sep='')

all_answers = []
for ii in range(2, M+1):
    for jj in range(2, M+1):
        for kk in range(2, M+1):
            all_answers.append((ii, jj, kk))

for case in range(R):
    poss_answers = all_answers.copy()
    products = read_ints()
    for product in products:
        if product == 1:
            continue
        to_del = []
        for index, answer in enumerate(poss_answers):
            if product != answer[0] and product != answer[1] and product != answer[2] \
                    and product != (answer[0] * answer[1]) \
                    and product != (answer[0] * answer[2]) \
                    and product != (answer[1] * answer[2]) \
                    and product != (answer[0] * answer[1] * answer[2]):
                to_del.append(index)
        for ii in range(len(to_del)-1, -1, -1):
            del poss_answers[to_del[ii]]

    print(poss_answers[0][0], poss_answers[0][1], poss_answers[0][2], sep='')


