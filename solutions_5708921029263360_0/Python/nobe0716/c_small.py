__author__ = 'sunghyo.jung'

import sys

sys.setrecursionlimit(10000)

maximum_size_of_l = 0
maximum_sized_l = []


def back(clothes, l, d_jp, d_js, d_ps, k):
    global maximum_size_of_l
    if len(clothes) == 0:
        if len(l) > maximum_size_of_l:
            maximum_size_of_l = len(l)
            global maximum_sized_l
            maximum_sized_l = l
    if len(clothes) + len(l) < maximum_size_of_l:
        return

    for i in range(len(clothes)):
        j = clothes[i][0]
        p = clothes[i][1]
        s = clothes[i][2]
        k_jp = j * 100 + p
        k_js = j * 100 + s
        k_ps = p * 100 + s
        if d_jp[k_jp] < k and d_js[k_js] < k and d_ps[k_ps] < k:
            d_jp[k_jp] += 1
            d_js[k_js] += 1
            d_ps[k_ps] += 1
            back(clothes[i + 1:], l + [clothes[i]], d_jp, d_js, d_ps, k)
            d_jp[k_jp] -= 1
            d_js[k_js] -= 1
            d_ps[k_ps] -= 1

for t in range(1, int(input().strip()) + 1):
    jacket, pants, shirts, k = list(map(int, input().strip().split()))
    d_jp = {}
    d_js = {}
    d_ps = {}
    clothes = []

    maximum_size_of_l = 0
    for j in range(1, jacket + 1):
        for p in range(1, pants + 1):
            for s in range(1, shirts + 1):
                k_jp = j * 100 + p
                k_js = j * 100 + s
                k_ps = p * 100 + s
                d_jp[k_jp] = 0
                d_js[k_js] = 0
                d_ps[k_ps] = 0
                clothes.append((j,p,s))
    back(clothes, [], d_jp, d_js, d_ps, k)

    print("Case #%d: %d" % (t, maximum_size_of_l))
    for j, p, s in maximum_sized_l:
        print(j, p, s)


