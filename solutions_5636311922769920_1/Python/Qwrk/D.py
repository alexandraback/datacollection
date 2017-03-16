#
# def solve(k, c, s):
#     if k == 1: return [1]
#     p = pow(k, c)
#     return range(1, p + 1, (p - 1) // (k - 1))
#
#
# if __name__ == "__main__":
#     t = int(input())
#     for case in range(1, t + 1):
#         k, c, s = map(int, input().split())
#         print("Case #%d:" % case, *solve(k, c, s))
#
#
# def gen_all(k, c, w=None):
#     from itertools import product
#     def sim(s, c):
#         x = s
#         for _ in range(c):
#             r = ''
#             for i in x:
#                 if i == 'L':
#                     r += s
#                 else:
#                     r += 'G' * len(s)
#             x = r
#         return x
#
#     for start in product('LG', repeat=k):
#         st = ''.join(start)
#         s = sim(st, c - 1)
#         if w:
#             print(st, ''.join(s[i-1] for i in w))
#         else:
#             print(st, s)
#


def solve(k, c, s):
    import math
    trials = math.ceil(k / c)
    if trials > s: return None
    tab = [[t * c + i for i in range(c)] for t in range(trials)]
    if k % c != 0:
        tab[-1] = [0] * (k % c) + tab[-1][:(k % c)]
    res = []
    for r in tab:
        res.append(sum(x * k**i for i, x in enumerate(r[::-1])) + 1)
    return res


if __name__ == "__main__":
    t = int(input())
    for case in range(1, t + 1):
        k, c, s = map(int, input().split())
        res = solve(k, c, s)
        if res is None:
            print("Case #%d: IMPOSSIBLE" % case)
        else:
            print("Case #%d:" % case, *res)
