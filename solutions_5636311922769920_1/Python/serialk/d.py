#!/usr/bin/python3

def answer_equal(k, c, s):
    return ' '.join([str(1 + (k ** (c - 1)) * i) for i in range(s)])


def answer(k, c, s):
    if c == 1:
        return 'IMPOSSIBLE' if k > s else ' '.join(list(map(str, range(1, s + 1))))
    if k > s * 2:
        return 'IMPOSSIBLE'
    step = (k ** (c - 1))
    l = []
    for i in range(s):
        base = 1 + step * i
        if i > s // 2 + 1:
            l.append(base)
        else:
            l.append(base + step - 1 - i * k ** (c - 2))
    return ' '.join(list(map(str, l)))


T = int(input())
for i in range(T):
    k, c, s = list(map(int, input().split()))
    print('Case #{}: {}'.format(i + 1, answer(k, c, s)))
