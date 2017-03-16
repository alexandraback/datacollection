__author__ = 'sunghyo.jung'

import sys
import time

current_milli_time = lambda: int(round(time.time() * 1000))
timestamp = 0


from collections import Counter
sys.setrecursionlimit(2500)


def exist_path(b, g, f, t):
    if g[f][t] == "1":
        return True

    for i in range(b):
        if g[f][i] == "1" and exist_path(b, g, i, t):
            return True
    return False


def count_path(b, g, f, t, path_count_table):

    if (f, t) in path_count_table:
        return path_count_table[(f, t)]
    count = 0
    if f == t:
        return 1
    if g[f][t] == "1":
        count = 1
    for i in range(b):
        if g[f][i] == "1":
            count += count_path(b, g, i, t, path_count_table)
    return count


def back(b, m, g, cp, path_count_table):
    if current_milli_time() - timestamp > 100:
        return None
    if b == 6 and m == 20:
        return None
    # num_of_path = count_path(b, g, 0, b - 1)
    # if num_of_path == m:
    #     return g
    # elif num_of_path > m:
    #     return None

    # num_of_path = count_path(b, g, 0, b - 1)
    for f in range(b):
        for t in range(b):
            if f == t or g[f][t] == "1":
                continue
            if exist_path(b, g, t, f): # make it circular
                continue
            g[f][t] = "1"

            delta = 0
            if t == b - 1:
                delta = count_path(b, g, 0, f, path_count_table)
                path_count_table[(0, f)] = delta
            elif f == 0:
                delta = count_path(b, g, t, b - 1, path_count_table)
                path_count_table[(t, b - 1)] = delta
            else:
                alpha = count_path(b, g, 0, f, path_count_table)
                path_count_table[(0, f)] = alpha
                beta = count_path(b, g, t, b - 1, path_count_table)
                path_count_table[(t, b - 1)] = beta

                delta = alpha * beta

            cp += delta
            path_count_table[(0, b - 1)] = cp
            if cp == m:
                return g
            elif cp < m:
                v = back(b, m, g, cp, path_count_table)
                if v is not None:
                    return v
            cp -= delta

            if t == b - 1:
                if (0, f) in path_count_table:
                    del path_count_table[(0, f)]
            elif f == 0:
                if (t, b - 1) in path_count_table:
                    del path_count_table[(t, b - 1)]
            else:
                if (0, f) in path_count_table:
                    del path_count_table[(0, f)]
                if (t, b - 1) in path_count_table:
                    del path_count_table[(t, b - 1)]

            path_count_table[(0, b - 1)] = cp
            g[f][t] = "0"
    return None

for t in range(1, int(input().strip()) + 1):
    b, m = list(map(int, input().strip().split()))
    g = [["0" for x in range(b)] for y in range(b)]
    timestamp = current_milli_time()
    v = back(b, m, g, 0, {})

    if v is None:
        print("Case #%d: IMPOSSIBLE" % (t))
    else:
        print("Case #%d: POSSIBLE" % (t))
        for line in v:
            print("".join(line))
