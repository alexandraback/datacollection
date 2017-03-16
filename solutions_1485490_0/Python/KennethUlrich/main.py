import collections
import fractions
import functools
import itertools
import math
import operator

from sys import stdin
from multiprocessing import Pool

def solve_star(args):
    return solve(*args)

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return [int(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip()

def parse():
    n, m = read_ints()
    n_list, m_list = [], []
    ns = read_ints()
    ms = read_ints()
    for i in range(0, 2 * n, 2):
        n_list.append((ns[i], ns[i + 1]))
    for i in range(0, 2 * m, 2):
        m_list.append((ms[i], ms[i + 1]))
    return [n_list, m_list]

def solve_inner(n_list, m_list, cache, n_i=0, n_j=0, m_i=0, m_j=0):
    if n_i == len(n_list) or m_i == len(m_list):
        return 0
    k = (n_i, n_j, m_i, m_j)
    if k in cache:
        return cache[k]
    if n_list[n_i][1] == m_list[m_i][1]:
        n_left, m_left = n_list[n_i][0] - n_j, m_list[m_i][0] - m_j
        remove = min(n_left, m_left)
        if remove == n_left:
            n_j = 0
            n_i += 1
        else:
            n_j += remove 
        if remove == m_left:
            m_j = 0
            m_i += 1
        else:
            m_j += remove
        ret = remove + solve_inner(n_list, m_list, cache, n_i, n_j, m_i, m_j)
    else:
        a = solve_inner(n_list, m_list, cache, n_i + 1, 0, m_i, m_j)
        b = solve_inner(n_list, m_list, cache, n_i, n_j, m_i + 1, 0)
        ret = max(a, b)
    cache[k] = ret
    return ret
        
def solve(n_list, m_list):
    return solve_inner(n_list, m_list, {})

if __name__ == '__main__':
    pool = Pool()
    iter = pool.imap(solve_star, (parse() for i in range(read_int())))
    for i, result in enumerate(iter):
        print("Case #{}: {}".format(i + 1, result))